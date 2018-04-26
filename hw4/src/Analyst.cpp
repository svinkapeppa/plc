#include <iostream>
#include "Analyst.h"
#include "../RTTI.h"
#include "../utils.h"

void Analyst::Greet() {
  std::cout << "Hello! I'm an analyst!" << std::endl;
}

RTTI_CLASS_2(Analyst, "Analyst", Programmer, Mathematician)