#ifndef HW3_1_BASE_H
#define HW3_1_BASE_H

#define VIRTUAL_CLASS(class_t)\
class class_t {\
public:\
  std::string *id {nullptr};\
  std::string type = #class_t;\
  std::vector<std::string> bases;\
  class_t () {\
    auto tmp = new std::string;\
    *tmp = #class_t;\
    id = tmp;\
  }\

#define END_VIRTUAL_CLASS\
};\

#endif //HW3_1_BASE_H