#include <iostream>
#include "Exceptions.h"

int CException::Id() {
  return 1;
}

std::string CException::What() {
  return std::string("This is a default exception");
}

int CLogicException::Id() {
  return 2;
}

std::string CLogicException::What() {
  return std::string("This is a logic exception");
}