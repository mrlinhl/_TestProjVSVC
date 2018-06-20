#include"ProjTest.hpp"
#include<iostream>

ProjTest_Class::ProjTest_Class(void) : name_("NULL"), var_(0) {
  Show_Initial();
  Show_Status();
}

ProjTest_Class::ProjTest_Class(const std::string & name, int var)
  : name_(name), var_(var) {
  Show_Initial();
  Show_Status();
}

ProjTest_Class::ProjTest_Class(const ProjTest_Class* toCopy)
  : name_(toCopy->name_), var_(toCopy->var_) {
  Show_Copy();
  Show_Status();
}

ProjTest_Class::ProjTest_Class(const ProjTest_Class& toCopy)
  : name_(toCopy.name_), var_(toCopy.var_) {
  Show_Copy();
  Show_Status();
}

ProjTest_Class::~ProjTest_Class(void) {
  std::cout << "ProjTest_Class Deletes!  ";
  Show_Status();
}

void ProjTest_Class::Show_Status(void) const {
  std::cout << "Show :Name is " << name_ << "; Var is " << var_ << std::endl;
}

void  ProjTest_Class::Test_Static(void) {
  std::cout << "ProjTest_Class::Test_Static() Work!" << std::endl;
}

void ProjTest_Class::Show_Initial() const {
  std::cout << "ProjTest_Class Create!  ";
}

void ProjTest_Class::Show_Copy() const {
  std::cout << "ProjTest_Class Copy!  ";
}

void main(int argc, char ** argv) {
  for (int i = 0; i < argc; i++) {
    printf("Argument %d is %s.\n", i, argv[i]);
  }
  std::cout << "I'm ProjTest!" << std::endl;
  ProjTest_Class::Test_Static();
  ProjTest_Class object = ProjTest_Class("Object", 100);
  ProjTest_Class* pointer = new ProjTest_Class();
  pointer->Set_name("Pointer");
  std::cout << "pointer Name is " << pointer->Get_name() << std::endl;
  ProjTest_Class object2(pointer);
  delete pointer;
  ProjTest_Class object3(object);
  object2.Show_Status();
  object3.Show_Status();
  system("pause");
}
