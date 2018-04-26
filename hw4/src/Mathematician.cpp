#include <iostream>
#include "Mathematician.h"
#include "../RTTI.h"
#include "../utils.h"

RTTI_CLASS_1(Mathematician, "Programmer", Person)

void Mathematician::Greet() {
  std::cout << "Hello! I'm a mathematician!" << std::endl;
}
