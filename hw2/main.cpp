#include <iostream>
#include "utils.h"

void broadcast();
void weather();

int main() {
  TRY {
    TRY {
      broadcast();
    } CATCH(CLogicException*) {
      std::cout << "False alarm" << std::endl;
    } FINALLY;
    THROW(CException);
  } CATCH(CLogicException*) {
    std::cout << "Correct exception" << std::endl;
  } FINALLY;

  return 0;
}

void broadcast() {
  std::cout << "Start of the broadcast" << std::endl;
  weather();
}

void weather() {
  std::cout << "The weather today is fine" << std::endl;
  THROW(CLogicException);
}