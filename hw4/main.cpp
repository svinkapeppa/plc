#include <iostream>
#include "RTTI.h"
#include "utils.h"
#include "src/Person.h"
#include "src/Programmer.h"
#include "src/Analyst.h"

int main() {
  std::cout << "[*] SIMPLE DOWNCASTING" << std::endl;
  Person *person1 = new Programmer;
  Programmer *programmer;
  RTTI_CAST(programmer, Programmer, person1)
  std::string type1;
  TYPE_NAME(type1, programmer)
  std::cout << type1 << std::endl;
  if (programmer) {
    programmer->Greet();
  }
  std::cout << "[x] SIMPLE DOWNCASTING" << std::endl;

  std::cout << std::endl << "[*] COMPLEX DOWNCASTING" << std::endl;
  Mathematician *person2 = new Analyst;
  Analyst *analyst;
  RTTI_CAST(analyst, Analyst, person2)
  std::string type2;
  TYPE_NAME(type2, analyst)
  std::cout << type2 << std::endl;
  if (analyst) {
    analyst->Greet();
  }
  std::cout << "[x] COMPLEX DOWNCASTING" << std::endl;

  std::cout << std::endl << "[*] STATIC TYPE NAME" << std::endl;
  std::string type3 = STATIC_TYPE_NAME(Person)
  std::cout << type3 << std::endl;
  std::cout << "[x] STATIC TYPE NAME" << std::endl;

  return 0;
}