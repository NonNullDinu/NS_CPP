#include "uniform_mat4.h"

#include <GL/glew.h>
#include <GL/gl.h>

uniform_mat4::uniform_mat4(string name) : uniform(name)
{
    //ctor
}

uniform_mat4::~uniform_mat4()
{
    //dtor
}

void uniform_mat4::load(mat4 *mat)
{
    float v[] = {mat->m00, mat->m01, mat->m02, mat->m03,
                 mat->m10, mat->m11, mat->m12, mat->m13,
                 mat->m20, mat->m21, mat->m22, mat->m23,
                 mat->m30, mat->m31, mat->m32, mat->m33
                };
    glUniformMatrix4fv(this->loc, 1, false, &v[0]);
}
