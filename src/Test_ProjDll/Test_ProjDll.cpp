#include"ProjDll\ProjDll.hpp"
#include"ProjLib\ProjLib.hpp"
#include<iostream>
using namespace std;

void main(int argc, char ** argv) {
  for (int i = 0; i < argc; i++) {
    printf("Argument %d is %s.\n", i, argv[i]);
  }
    
  cout << "I'm Test_Dll!" << endl;
  cout << "projdll_num = " << projdll_num << endl;
  ProjDll_Func();
  ProjDll_Class testdll;
  cout << "projlib_num = " << projlib_num << endl;
  ProjLib_Func();
  ProjLib_Class testlib;
  system("pause");
}
