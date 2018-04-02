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

  void Logout();
};

class CMaster {
private:
  jmp_buf env;
  CMaster *prev;
  CObject *object;
public:
  CMaster();

  virtual ~CMaster();

  CObject *GetObject();

  void SetObject(CObject *object_);
};

#endif //HW2_OBJECTS_H