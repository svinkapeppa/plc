#ifndef HW3_UTILS_H
#define HW3_UTILS_H

#define DECLARE_METHOD(methodName)\
  static void methodName() {\

#define END_DECLARATION\
  }\

#define VIRTUAL_CALL(instance, method)\
if (instance.id == 1) {\
  for (auto i = 0; i < instance.methodNames.size(); ++i) {\
    if (instance.methodNames[i] == method) {\
      instance.methods[i]();\
      break;\
    }\
    if (i == instance.methodNames.size() - 1) {\
      std::cout << "ERROR: There is no such function" << std::endl;\
    }\
  }\
} else {\
  for (auto i = 0; i < instance.methodNamesDerived.size(); ++i) {\
    if (instance.methodNamesDerived[i] == method) {\
      instance.methodsDerived[i]();\
      break;\
    }\
    if (i == instance.methodNamesDerived.size() - 1) {\
      for (auto i = 0; i < instance.methodNames.size(); ++i) {\
        if (instance.methodNames[i] == method) {\
          instance.methods[i]();\
          break;\
        }\
        if (i == instance.methodNames.size() - 1) {\
          std::cout << "ERROR: There is no such function" << std::endl;\
        }\
      }\
    }\
  }\
}\

#endif //HW3_UTILS_H
