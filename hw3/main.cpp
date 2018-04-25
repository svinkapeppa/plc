#include <iostream>
#include "utils.h"
#include "Base.h"
#include "Derived.h"

VIRTUAL_CLASS(Base)
  static const int epoch = 0;
  DECLARE_METHOD(Common)
    std::cout << "It is an original method in Base class" << std::endl;
  END_DECLARATION
  DECLARE_METHOD(BaseDefault)
    std::cout << "It is a default method in Base class" << std::endl;
  END_DECLARATION
  VIRTUAL_CLASS_CONSTRUCTOR(Base)
    REGISTER_METHOD(Base, Common, "Common")
    REGISTER_METHOD(Base, BaseDefault, "BaseDefault")
  END_VIRTUAL_CLASS_CONSTRUCTOR
END_VIRTUAL_CLASS

VIRTUAL_CLASS_DERIVED(Base, Derived)
  DECLARE_METHOD(Common)
    std::cout << "This is an overridden method in Derived class" << std::endl;
  END_DECLARATION
  DECLARE_METHOD(DerivedDefault)
    std::cout << "It is a default method in Derived class" << std::endl;
  END_DECLARATION
  VIRTUAL_CLASS_DERIVED_CONSTRUCTOR(Derived)
    REGISTER_METHOD_DERIVED(Derived, DerivedDefault, "DerivedDefault")
    REGISTER_METHOD_DERIVED(Derived, Common, "Common")
  END_VIRTUAL_CLASS_DERIVED_CONSTRUCTOR
END_VIRTUAL_CLASS_DERIVED

int main() {
  std::cout << "[*] Setting up the environment" << std::endl;
  Base base;
  Derived derived;
  auto super = reinterpret_cast<Base*>(&derived);
  std::cout << "[x] Environment is ready" << std::endl;

  std::cout << std::endl << "[*] BASE CLASS" << std::endl;
  std::cout << "base epoch: " << base.epoch << std::endl;
  VIRTUAL_CALL(base, "Common")
  VIRTUAL_CALL(base, "BaseDefault")
  VIRTUAL_CALL(base, "DerivedDefault")
  std::cout << "[x] BASE CLASS" << std::endl;

  std::cout << std::endl << "[*] DERIVED CLASS" << std::endl;
  std::cout << "derived epoch: " << derived.epoch << std::endl;
  VIRTUAL_CALL(derived, "Common")
  VIRTUAL_CALL(derived, "BaseDefault")
  VIRTUAL_CALL(derived, "DerivedDefault")
  std::cout << "[x] DERIVED CLASS" << std::endl;

  std::cout << std::endl << "[*] POLYMORPHISM" << std::endl;
  std::cout << "super epoch: " << super->epoch << std::endl;
  VIRTUAL_CALL((*super), "Common")
  VIRTUAL_CALL((*super), "BaseDefault")
  VIRTUAL_CALL((*super), "DerivedDefault")
  std::cout << "[x] POLYMORPHISM" << std::endl;

  return 0;
}