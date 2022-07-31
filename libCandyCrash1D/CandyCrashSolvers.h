// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LIBCANDYCRASH1D_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LIBCANDYCRASH1D_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LIBCANDYCRASH1D_EXPORTS
#define LIBCANDYCRASH1D_API __declspec(dllexport)
#else
#define LIBCANDYCRASH1D_API __declspec(dllimport)
#endif

#include <string>

LIBCANDYCRASH1D_API std::string recursive_iterator_approach(const std::string& input);

LIBCANDYCRASH1D_API std::string stack_approach(const std::string& input);


