#ifndef HW2_CMACROS_H
#define HW2_CMACROS_H

#include <csetjmp>
#include <cstdlib>
#include "Objects.h"

#define TRY {\
  CMaster slave;\
  if (1) {\

#define FINALLY\
    }\
  }\

#endif //HW2_CMACROS_H