#include <assert.h>

#if defined(__MINGW32__)

#define REQUIRE(assertion, what) \
    if (!(assertion)) _assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
    if (!(assertion)) _assert (what, __FILE__, __LINE__)

#else

#define REQUIRE(assertion, what) if (!(assertion)) __assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) if (!(assertion)) __assert (what, __FILE__, __LINE__)

#endif