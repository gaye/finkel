#ifndef _IMI_THRIFT_WIN32_H_
#define _IMI_THRIFT_WIN32_H_

#ifdef _WIN32
#pragma comment(lib, "thriftnb.lib")
#pragma comment(lib, "libevent.lib")
#pragma comment(lib, "pthreadVC2.lib")
#pragma comment(lib, "ws2_32.lib")
#endif

#include <concurrency/ThreadManager.h>
#include <concurrency/PosixThreadFactory.h>
#include <protocol/TBinaryProtocol.h>
#include <server/TNonblockingServer.h>
#include <async/TEvhttpServer.h>
#include <async/TAsyncBufferProcessor.h>
#include <async/TAsyncProtocolProcessor.h>


#include <event2/event.h>
#include <event2/thread.h>

#include <iostream>
#include <stdexcept>
#include <sstream>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>



#ifdef _WIN32
#define snprintf _snprintf_c
#endif



static void _log_cb(int severity, const char *msg) {
    static const char* sev[4] = {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR"
    };
#ifdef _WIN32
    int socket_errno = WSAGetLastError();
#endif
    std::cout << sev[severity] << ": " << msg << std::endl;
}


class ThriftWin32EventManager
{
    event_base *base;
    event_config *conf;
public:
    ThriftWin32EventManager()
    {

        conf = event_config_new();

#ifdef _WIN32
        WORD wVersionRequested;
        WSADATA wsaData;
        int err;

        /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
        wVersionRequested = MAKEWORD(2, 2);

        err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
            /* Tell the user that we could not find a usable */
            /* Winsock DLL.                                  */
            printf("WSAStartup failed with error: %d\n", err);

            // TODO Throw exception??
        }

        evthread_use_windows_threads();

        event_config_set_flag(conf, EVENT_BASE_FLAG_STARTUP_IOCP);
#endif

        base = event_base_new_with_config(conf);
        const char ** methods = event_get_supported_methods();

        //std::cout << "Version: " << event_get_version() << std::endl;
        //std::cout << "Method: " << event_base_get_method(base) << std::endl;
        //std::cout << "Features: 0x" << std::hex << event_base_get_features(base) << std::endl;
        //std::cout << "Base: " << base << std::endl;
        //while(*methods) {
        //    std::cout << "Method: " << *methods++ << std::endl;
        //}

        event_set_log_callback(_log_cb);

    }

    boost::shared_ptr< ::apache::thrift::server::TNonblockingServer > createNonblockingServer( boost::shared_ptr<::apache::thrift::TProcessor> processor,
        boost::shared_ptr<::apache::thrift::protocol::TProtocolFactory> protocolFactory, int port, unsigned int thread_count = 15)
    {
        using namespace apache::thrift::concurrency;
        using namespace apache::thrift::async;

        boost::shared_ptr<ThreadManager> threadManager =
            ThreadManager::newSimpleThreadManager(thread_count);
        boost::shared_ptr<PosixThreadFactory> threadFactory = boost::shared_ptr<
            PosixThreadFactory> (new PosixThreadFactory());
        threadManager->threadFactory(threadFactory);
        threadManager->start();

        return boost::shared_ptr< ::apache::thrift::server::TNonblockingServer > ( new ::apache::thrift::server::TNonblockingServer(processor, protocolFactory, port, threadManager) );
    }


    void releaseEventManager( void )
    {
        event_base_free(base);
        event_config_free(conf);

    }

};


#endif
