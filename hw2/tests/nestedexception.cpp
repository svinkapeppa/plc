#include <iostream>
#include "../utils.h"

void broad();
void weather();

int main() {
  std::cout << "This test case is about nested exception handling" << std::endl;
  TRY {
    TRY {
      broad();
    } CATCH(CLogicError*) {
      std::cout << "Nested exception caught" << std::endl;
    } FINALLY;
  } CATCH(CException*) {
    std::cout << "Wrapping exception caught" << std::endl;
  } FINALLY;

  return 0;
}

void broad() {
  std::cout << "Start of the broadcast" << std::endl;
  weather();
}

void weather() {
  std::cout << "The weather today is fine" << std::endl;
  THROW(CLogicError);
}