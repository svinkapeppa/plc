#ifndef HW4_UTILS_H
#define HW4_UTILS_H

#define STATIC_TYPE_INFO(T)\
T::StaticInfo();\

#define STATIC_TYPE_NAME(T)\
T::StaticInfo().GetName();\

#define TYPE_INFO(typeInfo, p)\
if ((p)) {\
  (typeInfo) = (p)->VirtualInfo();\
} else {\
  (typeInfo) = CTypeId::Null();\
}\

#define TYPE_NAME(typeName, p)\
if ((p)) {\
  (typeName) = (p)->VirtualInfo().GetName();\
} else {\
  (typeName) = CTypeId::Null().GetName();\
}\

#define RTTI_CAST(ptr, T, p)\
if ((p)) {\
  (ptr) = (T*)((p)->Cast(T::StaticInfo()));\
} else {\
  (ptr) = 0;\
}\

#define ENABLE_RTTI \
public:\
  static CTypeId StaticInfo();\
  virtual CTypeId VirtualInfo() const;\
  virtual void* Cast(CTypeId obj);\
private:\
  static const CTypeInfo _obj;\

#define RTTI_CLASS(cls, name)\
  CTypeId cls::StaticInfo() {\
    return &_obj;\
  }\
  CTypeId cls::VirtualInfo() const {\
    return &_obj;\
  }\
  void* cls::Cast(CTypeId obj) {\
    if (obj == &_obj) {\
      return this;\
    }\
    return 0;\
  }\
  const CTypeInfo cls::_obj(name);\

#define RTTI_CLASS_1(cls, name, parent)\
  CTypeId cls::StaticInfo() {\
    return &_obj;\
  }\
  CTypeId cls::VirtualInfo() const {\
    return &_obj;\
  }\
  void* cls::Cast(CTypeId obj){\
    if (obj == &_obj) {\
      return this;\
    }\
    void* ptr;\
    if ((ptr = parent::Cast(obj))) {\
      return ptr;\
    }\
    return 0;\
  }\
  const CTypeInfo cls::_obj(name);\

#define RTTI_CLASS_2(cls, name, parent1, parent2)\
  CTypeId cls::StaticInfo() {\
    return &_obj;\
  }\
  CTypeId cls::VirtualInfo() const {\
    return &_obj;\
  }\
  void* cls::Cast(CTypeId obj){\
    if (obj == &_obj) {\
      return this;\
    }\
    void* ptr;\
    if ((ptr = parent1::Cast(obj))) {\
      return ptr;\
    } else if ((ptr = parent2::Cast(obj))) {\
      return ptr;\
    }\
    return 0;\
  }\
  const CTypeInfo cls::_obj(name);\

#define RTTI_CLASS_3(cls, name, parent1, parent2, parent3)\
  CTypeId cls::StaticInfo() {\
    return &_obj;\
  }\
  CTypeId cls::VirtualInfo() const {\
    return &_obj;\
  }\
  void* cls::Cast(CTypeId obj){\
    if (obj == &_obj) {\
      return this;\
    }\
    void* ptr;\
    if ((ptr = parent1::Cast(obj))) {\
      return ptr;\
    } else if ((ptr = parent2::Cast(obj))) {\
      return ptr;\
    } else if ((ptr = parent3::Cast(obj))) {\
      return ptr;\
    }\
    return 0;\
  }\
  const CTypeInfo cls::_obj(name);\

#endif //HW4_UTILS_H