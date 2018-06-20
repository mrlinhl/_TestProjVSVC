#ifdef PROJDLL_EXPORTS
#define PROJDLL_API __declspec(dllexport)
#else
#define PROJDLL_API __declspec(dllimport)
#endif

//Export Variable
extern PROJDLL_API int projdll_num;

//Export Function
PROJDLL_API void ProjDll_Func(void);

//Export Class
class PROJDLL_API ProjDll_Class {
 public:
  ProjDll_Class(void);
  ~ProjDll_Class(void);
};
