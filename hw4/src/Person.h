#ifndef HW4_TESTER_H
#define HW4_TESTER_H

#include "../RTTI.h"
#include "../utils.h"

class Person {
public:
  virtual void Greet();
  ENABLE_RTTI
};

#endif //HW4_TESTER_H