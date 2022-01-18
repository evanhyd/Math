#include <iostream>
#include <iomanip>

#define DEBUG


#ifdef DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define DEBUG_MEMORY() (_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF))


#define DEBUG_LOG(obj, debug_mode) if (debug_mode) std::cout << (obj) << std::endl

#endif
