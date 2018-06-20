#ifndef _TESTPROJVSVC_PROJTEST_H_
#define _TESTPROJVSVC_PROJTEST_H_

#include<string>

class ProjTest_Class {
 public:
  ProjTest_Class(void);
  ProjTest_Class(const std::string& name, int var);
  ProjTest_Class(const ProjTest_Class* toCopy);
  ProjTest_Class(const ProjTest_Class& toCopy);
  ~ProjTest_Class(void);

  static void Test_Static(void);
  void Show_Status(void) const;

  void Set_name(const std::string& name) {
    name_ = name;
  }
  const std::string& Get_name(void) const {
    return name_;
  }

 private:
  void Show_Initial (void) const;
  void Show_Copy(void) const;

  std::string name_;
  int var_;
};

#endif // _TESTPROJVSVC_PROJTEST_H_
