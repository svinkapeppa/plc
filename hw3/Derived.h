#ifndef HW3_DERIVED_H
#define HW3_DERIVED_H

#include <vector>
#include <string>

#define VIRTUAL_CLASS_DERIVED(base_class_t, class_t)\
class class_t : public base_class_t {\
public:\
  static const int id = 2;\

#define VIRTUAL_CLASS_DERIVED_CONSTRUCTOR(class_t)\
  class_t() {\

#define REGISTER_METHOD_DERIVED(class_t, method, methodName)\
  for (auto i = 0; i < class_t::methodNames.size(); ++i) {\
    if (methodName == class_t::methodNames[i]) {\
      class_t::methods[i] = method;\
      return;\
    }\
  }\
  class_t::methodNamesDerived.emplace_back(methodName);\
  class_t::methodsDerived.emplace_back(method);\


#define END_VIRTUAL_CLASS_DERIVED_CONSTRUCTOR\
  }\

#define END_VIRTUAL_CLASS_DERIVED\
};\

#endif //HW3_DERIVED_H
