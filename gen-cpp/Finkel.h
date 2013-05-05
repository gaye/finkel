/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Finkel_H
#define Finkel_H

#include <thrift/TDispatchProcessor.h>
#include "finkel_types.h"



class FinkelIf {
 public:
  virtual ~FinkelIf() {}
  virtual bool start() = 0;
  virtual bool stop() = 0;
  virtual void TakeScreenshot(Bitmap& _return) = 0;
  virtual bool ProcessUserInput(const std::vector<UserInput> & inputSequence) = 0;
};

class FinkelIfFactory {
 public:
  typedef FinkelIf Handler;

  virtual ~FinkelIfFactory() {}

  virtual FinkelIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(FinkelIf* /* handler */) = 0;
};

class FinkelIfSingletonFactory : virtual public FinkelIfFactory {
 public:
  FinkelIfSingletonFactory(const boost::shared_ptr<FinkelIf>& iface) : iface_(iface) {}
  virtual ~FinkelIfSingletonFactory() {}

  virtual FinkelIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(FinkelIf* /* handler */) {}

 protected:
  boost::shared_ptr<FinkelIf> iface_;
};

class FinkelNull : virtual public FinkelIf {
 public:
  virtual ~FinkelNull() {}
  bool start() {
    bool _return = false;
    return _return;
  }
  bool stop() {
    bool _return = false;
    return _return;
  }
  void TakeScreenshot(Bitmap& /* _return */) {
    return;
  }
  bool ProcessUserInput(const std::vector<UserInput> & /* inputSequence */) {
    bool _return = false;
    return _return;
  }
};


class Finkel_start_args {
 public:

  Finkel_start_args() {
  }

  virtual ~Finkel_start_args() throw() {}


  bool operator == (const Finkel_start_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Finkel_start_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_start_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Finkel_start_pargs {
 public:


  virtual ~Finkel_start_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_start_result__isset {
  _Finkel_start_result__isset() : success(false) {}
  bool success;
} _Finkel_start_result__isset;

class Finkel_start_result {
 public:

  Finkel_start_result() : success(0) {
  }

  virtual ~Finkel_start_result() throw() {}

  bool success;

  _Finkel_start_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Finkel_start_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Finkel_start_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_start_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_start_presult__isset {
  _Finkel_start_presult__isset() : success(false) {}
  bool success;
} _Finkel_start_presult__isset;

class Finkel_start_presult {
 public:


  virtual ~Finkel_start_presult() throw() {}

  bool* success;

  _Finkel_start_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Finkel_stop_args {
 public:

  Finkel_stop_args() {
  }

  virtual ~Finkel_stop_args() throw() {}


  bool operator == (const Finkel_stop_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Finkel_stop_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_stop_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Finkel_stop_pargs {
 public:


  virtual ~Finkel_stop_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_stop_result__isset {
  _Finkel_stop_result__isset() : success(false) {}
  bool success;
} _Finkel_stop_result__isset;

class Finkel_stop_result {
 public:

  Finkel_stop_result() : success(0) {
  }

  virtual ~Finkel_stop_result() throw() {}

  bool success;

  _Finkel_stop_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Finkel_stop_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Finkel_stop_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_stop_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_stop_presult__isset {
  _Finkel_stop_presult__isset() : success(false) {}
  bool success;
} _Finkel_stop_presult__isset;

class Finkel_stop_presult {
 public:


  virtual ~Finkel_stop_presult() throw() {}

  bool* success;

  _Finkel_stop_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Finkel_TakeScreenshot_args {
 public:

  Finkel_TakeScreenshot_args() {
  }

  virtual ~Finkel_TakeScreenshot_args() throw() {}


  bool operator == (const Finkel_TakeScreenshot_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Finkel_TakeScreenshot_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_TakeScreenshot_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Finkel_TakeScreenshot_pargs {
 public:


  virtual ~Finkel_TakeScreenshot_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_TakeScreenshot_result__isset {
  _Finkel_TakeScreenshot_result__isset() : success(false) {}
  bool success;
} _Finkel_TakeScreenshot_result__isset;

class Finkel_TakeScreenshot_result {
 public:

  Finkel_TakeScreenshot_result() {
  }

  virtual ~Finkel_TakeScreenshot_result() throw() {}

  Bitmap success;

  _Finkel_TakeScreenshot_result__isset __isset;

  void __set_success(const Bitmap& val) {
    success = val;
  }

  bool operator == (const Finkel_TakeScreenshot_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Finkel_TakeScreenshot_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_TakeScreenshot_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_TakeScreenshot_presult__isset {
  _Finkel_TakeScreenshot_presult__isset() : success(false) {}
  bool success;
} _Finkel_TakeScreenshot_presult__isset;

class Finkel_TakeScreenshot_presult {
 public:


  virtual ~Finkel_TakeScreenshot_presult() throw() {}

  Bitmap* success;

  _Finkel_TakeScreenshot_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Finkel_ProcessUserInput_args__isset {
  _Finkel_ProcessUserInput_args__isset() : inputSequence(false) {}
  bool inputSequence;
} _Finkel_ProcessUserInput_args__isset;

class Finkel_ProcessUserInput_args {
 public:

  Finkel_ProcessUserInput_args() {
  }

  virtual ~Finkel_ProcessUserInput_args() throw() {}

  std::vector<UserInput>  inputSequence;

  _Finkel_ProcessUserInput_args__isset __isset;

  void __set_inputSequence(const std::vector<UserInput> & val) {
    inputSequence = val;
  }

  bool operator == (const Finkel_ProcessUserInput_args & rhs) const
  {
    if (!(inputSequence == rhs.inputSequence))
      return false;
    return true;
  }
  bool operator != (const Finkel_ProcessUserInput_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_ProcessUserInput_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Finkel_ProcessUserInput_pargs {
 public:


  virtual ~Finkel_ProcessUserInput_pargs() throw() {}

  const std::vector<UserInput> * inputSequence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_ProcessUserInput_result__isset {
  _Finkel_ProcessUserInput_result__isset() : success(false) {}
  bool success;
} _Finkel_ProcessUserInput_result__isset;

class Finkel_ProcessUserInput_result {
 public:

  Finkel_ProcessUserInput_result() : success(0) {
  }

  virtual ~Finkel_ProcessUserInput_result() throw() {}

  bool success;

  _Finkel_ProcessUserInput_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const Finkel_ProcessUserInput_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Finkel_ProcessUserInput_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Finkel_ProcessUserInput_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Finkel_ProcessUserInput_presult__isset {
  _Finkel_ProcessUserInput_presult__isset() : success(false) {}
  bool success;
} _Finkel_ProcessUserInput_presult__isset;

class Finkel_ProcessUserInput_presult {
 public:


  virtual ~Finkel_ProcessUserInput_presult() throw() {}

  bool* success;

  _Finkel_ProcessUserInput_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class FinkelClient : virtual public FinkelIf {
 public:
  FinkelClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  FinkelClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool start();
  void send_start();
  bool recv_start();
  bool stop();
  void send_stop();
  bool recv_stop();
  void TakeScreenshot(Bitmap& _return);
  void send_TakeScreenshot();
  void recv_TakeScreenshot(Bitmap& _return);
  bool ProcessUserInput(const std::vector<UserInput> & inputSequence);
  void send_ProcessUserInput(const std::vector<UserInput> & inputSequence);
  bool recv_ProcessUserInput();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class FinkelProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<FinkelIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (FinkelProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_start(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_stop(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_TakeScreenshot(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ProcessUserInput(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  FinkelProcessor(boost::shared_ptr<FinkelIf> iface) :
    iface_(iface) {
    processMap_["start"] = &FinkelProcessor::process_start;
    processMap_["stop"] = &FinkelProcessor::process_stop;
    processMap_["TakeScreenshot"] = &FinkelProcessor::process_TakeScreenshot;
    processMap_["ProcessUserInput"] = &FinkelProcessor::process_ProcessUserInput;
  }

  virtual ~FinkelProcessor() {}
};

class FinkelProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  FinkelProcessorFactory(const ::boost::shared_ptr< FinkelIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< FinkelIfFactory > handlerFactory_;
};

class FinkelMultiface : virtual public FinkelIf {
 public:
  FinkelMultiface(std::vector<boost::shared_ptr<FinkelIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~FinkelMultiface() {}
 protected:
  std::vector<boost::shared_ptr<FinkelIf> > ifaces_;
  FinkelMultiface() {}
  void add(boost::shared_ptr<FinkelIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool start() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->start();
    }
    return ifaces_[i]->start();
  }

  bool stop() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->stop();
    }
    return ifaces_[i]->stop();
  }

  void TakeScreenshot(Bitmap& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->TakeScreenshot(_return);
    }
    ifaces_[i]->TakeScreenshot(_return);
    return;
  }

  bool ProcessUserInput(const std::vector<UserInput> & inputSequence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ProcessUserInput(inputSequence);
    }
    return ifaces_[i]->ProcessUserInput(inputSequence);
  }

};



#endif
