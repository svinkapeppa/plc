#ifndef HW3_BASE_H
#define HW3_BASE_H

#define VIRTUAL_CLASS(class_t)\
class class_t {\
public:\
  static std::map<std::string, void (*)()> __vtable;\
  std::map<std::string, void (*)()> *__reference;\
  int __ ## class_t ## __() {\
    auto _ = new std::map<std::string, void (*)()>;\
    *_ = __vtable;\
    __reference = _;\
    return 0;\
  }\
  int __ ## class_t ## init__ = __ ## class_t ## __();\

#define END_VIRTUAL_CLASS(class_t)\
};\
std::map<std::string, void (*)()> class_t::__vtable{};\

#endif //HW3_BASE_H