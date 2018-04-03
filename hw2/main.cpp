#include <iostream>
#include "utils.h"

int main() {
  TRY {
    CObject x;
    TRY {
      CObject y;
      CLogicException e;
      THROW(&e);
    }
    CATCH(CException*) {
      std::cout << "NESTED" << std::endl;
    }
    FINALLY;
    CException e;
    THROW(&e);
  }
  CATCH(CLogicException*) {
    std::cout << "CATCH" << std::endl;
  }
  FINALLY;
  return 0;
}