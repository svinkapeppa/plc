#include <iostream>
#include "Exceptions.h"

int CException::Id() {
  return 1;
}

std::string CException::What() {
  return std::string("This is a default exception");
}

int CLogicError::Id() {
  return 2;
}

std::string CLogicError::What() {
  return std::string("This is a logic exception");
}

int CRuntimeError::Id() {
  return 3;
}

std::string CRuntimeError::What() {
  return std::string("This is a runtime exception");
}

int CBadTypeid::Id() {
  return 4;
}

std::string CBadTypeid::What() {
  return std::string("This is a bad typeid exception");
}

int CBadCast::Id() {
  return 5;
}

std::string CBadCast::What() {
  return std::string("This is a bad cast exception");
}

int CBadWeakPtr::Id() {
  return 6;
}

std::string CBadWeakPtr::What() {
  return std::string("This is a bad weak ptr exception");
}

int CBadFunctionCall::Id() {
  return 7;
}

std::string CBadFunctionCall::What() {
  return std::string("This is a bad function call exception");
}

int CBadAlloc::Id() {
  return 8;
}

std::string CBadAlloc::What() {
  return std::string("This is a bad alloc exception");
}

int CBadException::Id() {
  return 9;
}

std::string CBadException::What() {
  return std::string("This is a bad exception");
}