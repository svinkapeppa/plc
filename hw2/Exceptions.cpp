#include <iostream>
#include "Exceptions.h"

CException::CException() {
  std::cout << "[x] Default exception has been thrown" << std::endl;
}

std::string CException::what() {
  return std::string("This is a default exception");
}

CLogicException::CLogicException() {
  std::cout << "[x] Logic exception has been thrown" << std::endl;
}

std::string CLogicException::what() {
  return std::string("This is a logic exception");
}