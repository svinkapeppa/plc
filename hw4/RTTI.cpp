#include "RTTI.h"

const CTypeInfo CTypeInfo::Null("NULL");

CTypeInfo::CTypeInfo(const std::string name) {
  _name = name;
}

const std::string CTypeInfo::GetName() const {
  return _name;
}

int CTypeInfo::Same(const CTypeInfo *p) const {
  return this == p || _name == p->_name;
}

CTypeId CTypeId::Null() {
  return &(CTypeInfo::Null);
}

CTypeId::CTypeId() {
  _id = Null()._id;
}

CTypeId::CTypeId(const CTypeInfo *id) {
  _id = id;
}

int CTypeId::operator==(CTypeId obj) const {
  return _id->Same(obj._id);
}

int CTypeId::operator!=(CTypeId obj) const {
  return !(_id->Same(obj._id));
}

const std::string CTypeId::GetName() const {
  return _id->GetName();
}