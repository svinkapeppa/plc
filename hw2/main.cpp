#include <iostream>
#include "utils.h"

int main() {
  TRY {
    CObject x;
    TRY {
      CObject y;
      THROW(2);
    }
    CATCH {
      std::cout << "NESTED" << std::endl;
    }
    FINALLY;
    THROW(1);
  }
  CATCH {
    std::cout << "CATCH" << std::endl;
  }
  FINALLY;
  return 0;
}