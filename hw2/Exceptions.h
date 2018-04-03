#ifndef HW2_EXCEPTIONS_H
#define HW2_EXCEPTIONS_H

class CException {
public:
  virtual std::string what();
};

class CLogicException : public CException {
public:
  virtual std::string what();
};

#endif //HW2_EXCEPTIONS_H