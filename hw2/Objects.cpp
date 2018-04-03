#include <iostream>
#include "Objects.h"

CMaster *master = nullptr;

CObject::CObject() {
  std::cout << "[*] Starting the process of new Object creation" << std::endl;
  if (master != nullptr) {
    this->SetPrev(master->GetObject());
    master->SetObject(this);
  }
  std::cout << "[x] The process of new Object creation is completed" << std::endl;
}

CObject::~CObject() {
  std::cout << "[*] Starting the process of Object destruction" << std::endl;
  this->Logout();
  std::cout << "[x] The process of Object destruction is completed" << std::endl;
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

CObject *CObject::GetPrev() {
  return prev;
}

CMaster::CMaster() {
  std::cout << "[*] Starting the process of new environmental point creation" << std::endl;
  object = nullptr;
  prev = master;
  master = this;
  std::cout << "[x] The process of new environmental point creation is completed" << std::endl;
}

CMaster::~CMaster() {
  std::cout << "[*] Starting the process of environmental point destruction" << std::endl;
  master = prev;
  std::cout << "[x] The process of environmental point destruction is completed" << std::endl;
}

CObject *CMaster::GetObject() {
  return master->object;
}

void CMaster::SetObject(CObject *object_) {
  object = object_;
}

CMaster *CMaster::GetPrev() {
  return prev;
}