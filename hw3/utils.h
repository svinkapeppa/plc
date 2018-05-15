#ifndef HW3_UTILS_H
#define HW3_UTILS_H

#define METHOD(class_t, method)\
void __ ## class_t ## __ ## method ## __() {\

#define END_METHOD(class_t, method)\
}\
int __ ## class_t ## __ ## method ## __register__() {\
  class_t::__vtable[#method] = __ ## class_t ## __ ## method ## __;\
  return 0;\
}\
int __ ## class_t ## __ ## method ## __init__ = __ ## class_t ## __ ## method ## __register__();\

#define VIRTUAL_CALL(object, method)\
try {\
  auto it = object.__vtable.at(#method);\
  object.__reference->at(#method)();\
} catch (...) {\
  std::cout << "Error: " <<  #object << " doesn't have method named " << #method << std::endl;\
}\

#endif //HW3_UTILS_H
