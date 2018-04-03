#ifndef HW2_CMACROS_H
#define HW2_CMACROS_H

#include <csetjmp>
#include <cstdlib>
#include "Objects.h"
#include "Exceptions.h"

void Throw();

#define TRY {\
  CMaster slave;\
  auto *exc = new CException;\
  int env = setjmp(slave.env);\
  if (env == 0) {

#define CATCH(type)\
  } else if (dynamic_cast<type>(exc) != nullptr) {\
      std::cout << exc->what() << std::endl;\

#define FINALLY\
    }\
  }

#define THROW(type)\
  type exc_;\
  exc = &exc_;\
  Throw();

void Throw() {
  CMaster *tmp = master;
  CObject *object = master->GetObject();

  // Delete objects from stack frame
  while (object != nullptr) {
    CObject *objectBuf = object;
    object = object->GetPrev();
    objectBuf->~CObject();
  }

  // Change stack frame
  CMaster *fake = master;
  if (fake != nullptr) {
    master = fake->GetPrev();
  }

  longjmp(tmp->env, 1);
}

#endif //HW2_CMACROS_H