#ifndef DEBUG_HEADER
#define DEBUG_HEADER

// debug messages to remplace wxLogError
#define DEBUG_ACTIVE

#ifdef DEBUG_ACTIVE
    #include <iostream>
    #define LOG_MSG_NL(msg) std::cout << msg << std::endl
    #define LOG_MSG(msg) std::cout << msg
#else
    #define LOG_MSG_NL(msg)
    #define LOG_MSG(msg)
#endif

#endif // DEBUG_HEADER