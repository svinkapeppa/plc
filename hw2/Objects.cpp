#include "Objects.h"

CMaster *master = nullptr;

CObject::CObject() {
  if (master != nullptr) {
    this->SetPrev(master->GetObject());
    master->SetObject(this);
  }
}

CObject::~CObject() {
  this->Logout();
}

void CObject::Logout() {
  if (master != nullptr && prev != nullptr) {
    master->SetObject(prev);
    prev = nullptr;
  }
}

void CObject::SetPrev(CObject *object) {
  prev = object;
}

CMaster::CMaster() {
  object = nullptr;
  prev = master;
  master = this;
}

CMaster::~CMaster() {
  master = prev;
}

CObject *CMaster::GetObject() {
  return master->object;
}

void CMaster::SetObject(CObject *object_) {
  object = object_;
}