#include "uniform_float.h"
#include "GL/glew.h"

uniform_float::uniform_float(string name) : uniform(name)
{
    //ctor
}

uniform_float::~uniform_float()
{
    //dtor
}

void uniform_float::load(float v){
    glUniform1f(uniform::GetLoc(), v);
}
