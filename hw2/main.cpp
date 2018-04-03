#include <iostream>
#include "utils.h"

void weather();

int main() {
  TRY {
    weather();
//        THROW(CLogicException);
  }
  CATCH(CLogicException*) {
    std::cout << "last" << std::endl;
  }
  FINALLY;
  return 0;
}

void weather() {
  std::cout << "The weather today is fine" << std::endl;
  THROW(CLogicException);
}