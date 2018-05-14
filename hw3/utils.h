#ifndef HW3_1_UTILS_H
#define HW3_1_UTILS_H

std::map<std::string, void (*)()> table;

#define METHOD_DECLARATION(class_t, method)\
void class_t ## method() {\

#define END_METHOD_DECLARATION\
}\

#define METHOD_REGISTRATION(class_t, method)\
table[# class_t # method] = class_t ## method;\

#define VIRTUAL_CALL(object, method)\
if (object.bases.size()) {\
  for (int i = 0; i < object.bases.size(); ++i) {\
    try {\
      auto it = table.at(object.bases[i] + # method);\
      try {\
        table.at(*object.id + # method)();\
      } catch (...) {\
        it();\
      }\
      break;\
    } catch (...) {\
      if (i == object.bases.size() - 1) {\
        try {\
          table.at(*object.id + # method)();\
        } catch (...) {\
          std::cout << "Not implemented" << std::endl;\
        }\
      } else {\
        continue;\
      }\
    }\
  }\
} else {\
  try {\
    auto it = table.at(object.type + # method);\
    if (*object.id != object.type) {\
      try {\
        table.at(*object.id + # method)();\
      } catch (...) {\
        it();\
      }\
    } else {\
      it();\
    }\
  } catch (...) {\
    std::cout << "Not implemented" << std::endl;\
  }\
}\

#endif //HW3_1_UTILS_H
