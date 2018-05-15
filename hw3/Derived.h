#ifndef HW3_DERIVED_H
#define HW3_DERIVED_H

#define DERIVED_VIRTUAL_CLASS(class_t, base_class_t)\
class class_t : public base_class_t {\
public:\
  static std::map<std::string, void (*)()> __vtable;\
  int __ ## class_t ## __() {\
    auto _ = new std::map<std::string, void (*)()>;\
    *_ = __vtable;\
    __reference = _;\
    return 0;\
  }\
  int __ ## class_t ## __init__ = __ ## class_t ## __();\

#define END_DERIVED_VIRTUAL_CLASS(class_t, base_class_t)\
};\
std::map<std::string, void (*)()> class_t::__vtable{};\
int __ ## class_t ## __vtable__function__() {\
  class_t::__vtable = base_class_t::__vtable;\
}\
int __ ## class_t ## __vtable__init__ = __ ## class_t ## __vtable__function__();\

#endif //HW3_DERIVED_H
