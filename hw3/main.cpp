#include <iostream>
#include <map>
#include <vector>

#include "Base.h"
#include "Derived.h"
#include "utils.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VIRTUAL_CLASS(A)
END_VIRTUAL_CLASS

METHOD_DECLARATION(A, Func)
  std::cout << "AFunc" << std::endl;
END_METHOD_DECLARATION

METHOD_DECLARATION(A, Skate)
  std::cout << "ASkate" << std::endl;
END_METHOD_DECLARATION

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DERIVED_VIRTUAL_CLASS(B, A, std::vector<std::string>{"A"})
END_DERIVED_VIRTUAL_CLASS

METHOD_DECLARATION(B, Func)
  std::cout << "BFunc" << std::endl;
END_METHOD_DECLARATION

METHOD_DECLARATION(B, Sky)
  std::cout << "BSky" << std::endl;
END_METHOD_DECLARATION

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

auto ancestors = std::vector<std::string>{"B", "A"};

DERIVED_VIRTUAL_CLASS(C, B, ancestors)
END_DERIVED_VIRTUAL_CLASS

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  METHOD_REGISTRATION(A, Func);
  METHOD_REGISTRATION(A, Skate);
  METHOD_REGISTRATION(B, Func);
  METHOD_REGISTRATION(B, Sky);

  A a;
  B b;
  C c;
  auto d = reinterpret_cast<A*>(&b);
  auto e = reinterpret_cast<A*>(&c);

  VIRTUAL_CALL(a, Func)
  VIRTUAL_CALL(a, Skate)
  std::cout << std::endl;

  VIRTUAL_CALL(b, Func)
  VIRTUAL_CALL(b, Skate)
  VIRTUAL_CALL(b, Sky)
  std::cout << std::endl;

  VIRTUAL_CALL(c, Func)
  VIRTUAL_CALL(c, Skate)
  VIRTUAL_CALL(c, Sky)
  std::cout << std::endl;

  VIRTUAL_CALL((*d), Func)
  VIRTUAL_CALL((*d), Skate)
  VIRTUAL_CALL((*d), Sky)
  std::cout << std::endl;

  VIRTUAL_CALL((*e), Func)
  VIRTUAL_CALL((*e), Skate)
  VIRTUAL_CALL((*e), Sky)
}
