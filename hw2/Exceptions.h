#ifndef HW2_EXCEPTIONS_H
#define HW2_EXCEPTIONS_H

class CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CLogicError : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CRuntimeError : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CBadTypeid : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CBadCast : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CBadWeakPtr : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CBadFunctionCall : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CBadAlloc : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CBadException : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

#endif //HW2_EXCEPTIONS_H