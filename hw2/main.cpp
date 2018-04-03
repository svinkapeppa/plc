#include <iostream>
#include "utils.h"

int main() {
  TRY {
    CObject x;
    TRY {
      CObject y;
      THROW(CLogicException);
    }
    CATCH(CException*) {
      std::cout << "NESTED" << std::endl;
    }
    FINALLY;
    THROW(CException);
  }
  CATCH(CLogicException*) {
    std::cout << "CATCH" << std::endl;
  }
  FINALLY;
  return 0;
}