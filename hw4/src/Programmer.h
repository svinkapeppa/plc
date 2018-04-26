#ifndef HW4_PROGRAMMER_H
#define HW4_PROGRAMMER_H

#include "Person.h"
#include "../RTTI.h"
#include "../utils.h"

class Programmer : public Person {
public:
  virtual void Greet();
  ENABLE_RTTI
};

#endif //HW4_PROGRAMMER_H