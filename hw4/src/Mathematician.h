#ifndef HW4_MATHEMATICIAN_H
#define HW4_MATHEMATICIAN_H

#include "Person.h"
#include "../RTTI.h"
#include "../utils.h"

class Mathematician : public Person {
public:
  virtual void Greet();
  ENABLE_RTTI
};

#endif //HW4_MATHEMATICIAN_H
