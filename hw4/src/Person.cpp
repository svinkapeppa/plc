#include <iostream>
#include "Person.h"
#include "../RTTI.h"
#include "../utils.h"

RTTI_CLASS(Person, "Person")

void Person::Greet() {
  std::cout << "Hello! I'm a person!" << std::endl;
}