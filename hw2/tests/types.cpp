#include <iostream>
#include "../utils.h"

int main() {
  std::cout << "This test case is about exception types" << std::endl;
  TRY {
    THROW(CRuntimeError);
  } CATCH(CRuntimeError*) {
    std::cout << "Correct exception is caught" << std::endl;
  } FINALLY;

  TRY {
    THROW(CLogicError);
  } CATCH(CBadCast*) {
    std::cout << "Internships are cool" << std::endl;
  } CATCH(CLogicError*) {
    std::cout << "Tea is also great" << std::endl;
  } FINALLY;

  TRY {
    THROW(CBadException);
  } CATCH(CException*) {
    std::cout << "Default execption is always caught" << std::endl;
  } FINALLY;

  TRY {
    THROW(CException);
  } CATCH(CBadFunctionCall*) {
    std::cout << "I think I need to try my chances this time" << std::endl;
  } FINALLY;

  return 0;
}