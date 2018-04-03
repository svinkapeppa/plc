#ifndef HW2_CMACROS_H
#define HW2_CMACROS_H

#include <csetjmp>
#include <cstdlib>
#include "Objects.h"
#include "Exceptions.h"

void Throw(int id);

#define TRY {\
  CMaster slave;\
  auto exc = new CException;\
  int env = setjmp(slave.env);\
  if (env == 2) {\
    CLogicException exc_;\
    exc = &exc_;\
  }\
  if (env == 0) {

#define CATCH(type)\
  } else if (dynamic_cast<type>(exc) != nullptr) {\
      std::cout << exc->What() << std::endl;\

#define FINALLY\
    }\
  }

#define THROW(type)\
  type exc_;\
  CException *exc = &exc_;\
  Throw(exc_.Id());

void Throw(int id) {
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

  longjmp(tmp->env, id);
}

#endif //HW2_CMACROS_H