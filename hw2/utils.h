#ifndef HW2_CMACROS_H
#define HW2_CMACROS_H

#include <csetjmp>
#include <cstdlib>
#include "Objects.h"

void Throw(int n);
void Rethrow(int env);

#define TRY {\
  CMaster slave;\
  int env = setjmp(slave.env);\
  if (env == 0) {

#define CATCH\
  } else {

#define FINALLY\
    }\
  }\

#define THROW(exc)\
  Throw(exc);

#define RETHROW\
  Rethrow(env);

void Throw(int n) {
  CMaster *tmp = master;
  CObject *object = master->GetObject();

  while (object != nullptr) {
    CObject *objectBuf = object;
    object = object->GetPrev();
    objectBuf->~CObject();
  }

  longjmp(tmp->env, n);
}

void Rethrow(int env) {

}

#endif //HW2_CMACROS_H