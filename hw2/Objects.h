#ifndef HW2_OBJECTS_H
#define HW2_OBJECTS_H

#include <csetjmp>

class CObject {
private:
  CObject *prev;
public:
  CObject();
  virtual ~CObject();

  void SetPrev(CObject *object);
  CObject *GetPrev();
  void Logout();
};

class CMaster {
private:
  CMaster *prev;
  CObject *object;
public:
  jmp_buf env;

  CMaster();
  virtual ~CMaster();

  CObject *GetObject();
  void SetObject(CObject *object_);
  CMaster *GetPrev();
};

extern CMaster *master;

#endif //HW2_OBJECTS_H