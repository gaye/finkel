This directory packages everything needed to build a Thirft client or server under Windows using MSVC 2010.

Include is a rather ugly mismash of Thrift, libevent, boost and boost/tr1.  The purpose of this is so that a user (building a thrift client or server) can specify only this single directory as an include.

Similarly, all of the binary dependencies are in lib/Debug and lib/Release.

The source for this distribution is the 0.7.0 fork for non-blocking IO in windows:
https://github.com/aubonbeurre/thrift/blob/alex-0.7.0/README.non.blocking.Windows

The official apache 0.8 release may obviate the need to use this fork, but it's needed now to get non-blocking I/O.

-------------------------------------------------------------

Create a new Thrift client/server with MSVC 2010
------------------------------------------------
--- First, compile your .thrift file:

> thrift-0.70.exe -gen cpp agents.thrift

This should create a gen-cpp folder with several files.

-- Create your project for the server.

Using MSVC 2010, create a new project.

Copy/Add the files in gen-cpp to your project.

Add the "ThriftWin32/include" directory as a include directory:
Project->Properties... Configuration Properties->C/C++->General->Additional Include Directories

Add the "ThriftWin32/lib/($Configuration)" directory as a library directory:
Project->Properties... Configuration Properties->Linker->General->Additional Library Directories


