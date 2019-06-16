
/*************************** version.h **********************************/

#include <stdio.h>

// Pre-Development:
    //Ciutacu <ciutacu@yahoo.com>
//    To:Claudiu Ciutacu,Ciutacu Claudiu
    //Dec 14, 2016 at 09:28 PM
    //Permanent link: http://rextester.com/PVXET49221
    //Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x86 [v]
    //clang 3.7.0 [v]
    //gcc 4.9.3 [v]

    // Demo tree in C with getParent and getRoot
    // code by Twareintor (2016)

/*********** **************/
#define VER_MAJOR "100"
#define VER_MINOR "010"
/*********** **************/
#define VER_ALPHA
#define VER_BETA
#define VER_RELEASE
/*********** **************/
/*********** **************/
#ifdef VER_ALPHA
#define REL "A"
#elif defined(VER_BETA)
#define REL "B"
#else
#define REL "R"
#endif
/*********** **************/
#define COMPILED "03"
/*********** **************/
#define COMMENT "\nDemo tree in C with getParent and getRoot\n"\
	"See: Permanent link: http://rextester.com/PVXET49221"

void printVersion()
{
	printf("\nVERSION: " VER_MAJOR "." VER_MINOR "." REL COMPILED "/" __DATE__ " " __TIME__ " -- " COMMENT "\n");
} 


