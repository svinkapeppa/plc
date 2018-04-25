#ifndef HW3_BASE_H
#define HW3_BASE_H

#include <vector>
#include <string>

#define VIRTUAL_CLASS(class_t)\
class class_t {\
public:\
  static const int id = 1;\
  std::vector<std::string> methodNames;\
  std::vector<std::string> methodNamesDerived;\
  std::vector<void (*)()> methods;\
  std::vector<void (*)()> methodsDerived;\

#define VIRTUAL_CLASS_CONSTRUCTOR(class_t)\
  class_t() {\

#define REGISTER_METHOD(class_t, method, methodName)\
    class_t::methods.emplace_back(method);\
    class_t::methodNames.emplace_back(methodName);\

#define END_VIRTUAL_CLASS_CONSTRUCTOR\
  }\

#define END_VIRTUAL_CLASS\
};\

#endif //HW3_BASE_H
