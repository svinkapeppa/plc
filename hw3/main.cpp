#include <map>
#include <iostream>

#include "Base.h"
#include "Derived.h"
#include "utils.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VIRTUAL_CLASS(Car)
END_VIRTUAL_CLASS(Car)

METHOD(Car, What)
  std::cout << "It is a default class for handling Cars" << std::endl;
END_METHOD(Car, What)

METHOD(Car, GetCompany)
  std::cout << "Default Car Company" << std::endl;
END_METHOD(Car, GetCompany)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DERIVED_VIRTUAL_CLASS(Ford, Car)
END_DERIVED_VIRTUAL_CLASS(Ford, Car)

METHOD(Ford, GetCompany)
  std::cout << "Ford Inc" << std::endl;
END_METHOD(Ford, GetCompany)

METHOD(Ford, IsCool)
  std::cout << "So-so" << std::endl;
END_METHOD(Ford, IsCool)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DERIVED_VIRTUAL_CLASS(Mustang, Ford)
END_DERIVED_VIRTUAL_CLASS(Mustang, Ford)

METHOD(Mustang, IsCool)
  std::cout << "Definitely" << std::endl;
END_METHOD(Mustang, IsCool)

METHOD(Mustang, GetSpeed)
  std::cout << "Insane" << std::endl;
END_METHOD(Mustang, GetSpeed)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  std::cout << "[*] SETTING UP THE ENVIRONMENT" << std::endl;
  Car car;
  Ford ford;
  Mustang mustang;
  auto super = reinterpret_cast<Car *>(&ford);
  std::cout << "[x] SETTING UP THE ENVIRONMENT" << std::endl;

  std::cout << "[*] TEST CAR" << std::endl;
  VIRTUAL_CALL(car, What)
  VIRTUAL_CALL(car, GetCompany)
  VIRTUAL_CALL(car, IsCool)
  VIRTUAL_CALL(car, GetSpeed)
  std::cout << "[x] TEST CAR" << std::endl;

  std::cout << "[*] TEST FORD" << std::endl;
  VIRTUAL_CALL(ford, What)
  VIRTUAL_CALL(ford, GetCompany)
  VIRTUAL_CALL(ford, IsCool)
  VIRTUAL_CALL(ford, GetSpeed)
  std::cout << "[x] TEST FORD" << std::endl;

  std::cout << "[*] TEST MUSTANG" << std::endl;
  VIRTUAL_CALL(mustang, What)
  VIRTUAL_CALL(mustang, GetCompany)
  VIRTUAL_CALL(mustang, IsCool)
  VIRTUAL_CALL(mustang, GetSpeed)
  std::cout << "[x] TEST MUSTANG" << std::endl;

  std::cout << "[*] TEST CAST" << std::endl;
  VIRTUAL_CALL((*super), What)
  VIRTUAL_CALL((*super), GetCompany)
  VIRTUAL_CALL((*super), IsCool)
  VIRTUAL_CALL((*super), GetSpeed)
  std::cout << "[x] TEST CAST" << std::endl;

  return 0;
}