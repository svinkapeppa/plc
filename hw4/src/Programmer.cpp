#include <iostream>
#include "Programmer.h"
#include "../RTTI.h"
#include "../utils.h"

RTTI_CLASS_1(Programmer, "Programmer", Person)

void Programmer::Greet() {
  std::cout << "Hello! I'm a programmer!" << std::endl;
}
