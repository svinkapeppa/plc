#ifndef HW2_CMACROS_H
#define HW2_CMACROS_H

#include <csetjmp>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include "Objects.h"
#include "Exceptions.h"

void Throw(int id);

bool deleting = false;
bool caught = true;

#define TRY {\
  CMaster slave;\
  auto exc = new CException;\
  int env = setjmp(slave.env);\
  if (env == 2) {\
    CLogicError exc_;\
    exc = &exc_;\
  } else if (env == 3) {\
    CRuntimeError exc_;\
    exc = &exc_;\
  } else if (env == 4) {\
    CBadTypeid exc_;\
    exc = &exc_;\
  } else if (env == 5) {\
    CBadCast exc_;\
    exc = &exc_;\
  } else if (env == 6) {\
    CBadWeakPtr exc_;\
    exc = &exc_;\
  } else if (env == 7) {\
    CBadFunctionCall exc_;\
    exc = &exc_;\
  } else if (env == 8) {\
    CBadAlloc exc_;\
    exc = &exc_;\
  } else if (env == 9) {\
    CBadException exc_;\
    exc = &exc_;\
  }\
  if (env == 0) {

#define CATCH(type)\
  } else if (dynamic_cast<type>(exc) != nullptr) {\
      caught = true;

#define FINALLY\
    }\
  if (caught == false) {\
    std::cout << "Seems like there is no handler for this exception. Program is terminating" << std::endl;\
    exit(-1);\
  }\
  }

#define THROW(type)\
  caught = false;\
  type exc_;\
  CException *exc = &exc_;\
  Throw(exc_.Id());

void Throw(int id) {
  if (master == nullptr) {
    std::cout << "Seems like exception was thrown outside a try-catch block. Check your code" << std::endl;
    exit(-1);
  }

  if (deleting) {
    std::cout << "Throw call was invoked during another unhandled throw call. Program is terminating" << std::endl;
    exit(-1);
  }

  CMaster *tmp = master;
  CObject *object = master->GetObject();

  // Delete objects from stack frame
  deleting = true;
  while (object != nullptr) {
    CObject *objectBuf = object;
    object = object->GetPrev();
    objectBuf->~CObject();
  }
  deleting = false;

  // Change stack frame
  CMaster *fake = master;
  assert(fake != nullptr);
  master = fake->GetPrev();

  longjmp(tmp->env, id);
}

#endif //HW2_CMACROS_H