#ifndef HW4_ANALYST_H
#define HW4_ANALYST_H

#include "Mathematician.h"
#include "Programmer.h"
#include "../RTTI.h"
#include "../utils.h"

class Analyst : public Programmer, public Mathematician {
public:
  virtual void Greet();
  ENABLE_RTTI
};

#endif //HW4_ANALYST_H
