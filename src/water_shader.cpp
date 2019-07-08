#include "water_shader.h"

water_shader::water_shader() : shader_program("shaders/water/vertex.glsl", "shaders/water/fragment.glsl")
{
    //ctor
}

water_shader::~water_shader()
{
    //dtor
}
