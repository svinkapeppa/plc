#include <iostream>
#include "Exceptions.h"

std::string CException::what() {
  return std::string("This is a default exception");
}

std::string CLogicException::what() {
  return std::string("This is a logic exception");
}