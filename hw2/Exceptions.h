#ifndef HW2_EXCEPTIONS_H
#define HW2_EXCEPTIONS_H

class CException {
public:
  virtual int Id();
  virtual std::string What();
};

class CLogicException : public CException {
public:
  virtual int Id();
  virtual std::string What();
};

#endif //HW2_EXCEPTIONS_H