#ifndef HW4_RTTI_H
#define HW4_RTTI_H

#include <string>

class CTypeInfo;

class CTypeId {
public:
  CTypeId();
  CTypeId(const CTypeInfo *id);
  int operator==(CTypeId obj) const;
  int operator!=(CTypeId obj) const;
  const std::string GetName() const;
  static CTypeId Null();
private:
  const CTypeInfo *_id;
};

class CTypeInfo {
public:
  explicit CTypeInfo(std::string name);
  const std::string GetName() const;
  int Same(const CTypeInfo *obj) const;
private:
  std::string _name;
  static const CTypeInfo Null;
  friend class CTypeId;
};

#endif //HW4_RTTI_H