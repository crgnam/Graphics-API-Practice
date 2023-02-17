#ifndef __SHADER_INTERFACE_H_
#define __SHADER_INTERFACE_H_

#include <string>

namespace GAPIP {

void add_shader(unsigned int program, unsigned int type, const std::string& shader_path);

};

#endif