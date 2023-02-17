#ifndef __OPENGL_UTILS_H_
#define __OPENGL_UTILS_H_

// THIS IS MSVC SPECIFIC:
#ifdef __linux__
#define ASSERT(x) if (!(x)) __builtin_trap();
#elif _WIN32
#define ASSERT(x) if (!(x)) __debugbreak();
#endif

#define GLCall(x) GAPIP::GLClearError();\
	x;\
	ASSERT(GAPIP::GLLogCall(#x, __FILE__, __LINE__))

namespace GAPIP {

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

};
#endif