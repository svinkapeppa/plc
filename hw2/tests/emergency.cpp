#include <iostream>
#include "../utils.h"

class A : public CObject {
public:
  A();
  virtual ~A();
};

int main() {
  std::cout << "This test case is about emergency exit" << std::endl;
  TRY {
    A b;
    THROW(CException);
  } CATCH(CException*){
    std::cout << "I think skateboarding is great" << std::endl;
  } FINALLY;
}

A::A() {
  std::cout << "Object of type A was created" << std::endl;
}

A::~A() {
  std::cout << "Object of type A was destroyed" << std::endl;
  THROW(CException);
}