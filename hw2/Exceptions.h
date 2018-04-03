#ifndef HW2_EXCEPTIONS_H
#define HW2_EXCEPTIONS_H

class CException {
public:
  CException();

  virtual std::string what();
};

class CLogicException : public CException {
public:
  CLogicException();

  virtual std::string what();
};

#endif //HW2_EXCEPTIONS_H