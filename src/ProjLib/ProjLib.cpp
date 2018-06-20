#include "ProjLib.hpp"
#include<iostream>

int projlib_num = 111;

void ProjLib_Func(void) {
  std::cout << "ProjLibFunc Works!" << std::endl;
}

ProjLib_Class::ProjLib_Class(void) {
  std::cout << "ProjLib_Class Create!" << std::endl;
}
