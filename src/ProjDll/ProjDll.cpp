#include "ProjDll.hpp"
#include<iostream>

PROJDLL_API int projdll_num = 111;

PROJDLL_API void ProjDll_Func(void) {
  std::cout << "ProjDllFunc Works!" << std::endl;
}

ProjDll_Class::ProjDll_Class(void) {
  std::cout << "ProjDll_Class Creates!" << std::endl;
}

ProjDll_Class::~ProjDll_Class(void) {
  std::cout << "ProjDll_Class Deletes!" << std::endl;
}
