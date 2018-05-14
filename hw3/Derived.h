#ifndef HW3_1_DERIVED_H
#define HW3_1_DERIVED_H

#define DERIVED_VIRTUAL_CLASS(class_t, base_class_t, ancestors)\
class class_t : public base_class_t {\
public:\
  std::string type = #class_t;\
  std::vector<std::string> bases {ancestors};\
  class_t () {\
    auto tmp = new std::string;\
    *tmp = #class_t;\
    id = tmp;\
  }\

#define END_DERIVED_VIRTUAL_CLASS\
};\

#endif //HW3_1_DERIVED_H
