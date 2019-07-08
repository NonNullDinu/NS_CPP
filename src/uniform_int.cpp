#include "uniform_int.h"

#include "GL/glew.h"
#include "GL/gl.h"

uniform_int::uniform_int(string name) : uniform(name)
{}

uniform_int::~uniform_int()
{}

void uniform_int::load(int v)
{
    glUniform1i(this->loc, v);
}
