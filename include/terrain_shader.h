#ifndef TERRAIN_SHADER_H
#define TERRAIN_SHADER_H

#include "shader_program.h"
#include "uniform_mat4.h"
#include "mat4.h"
#include "uniform_float.h"

class terrain_shader : public shader_program
{
public:
    terrain_shader(mat4 *proj);
    virtual ~terrain_shader();
    uniform_mat4 viewMatrixu;
    uniform_mat4 projectionMatrixu;
    uniform_float x;
    uniform_float z;
protected:
    void postlink();

private:
    GLuint colorsBuffer;
};

#endif // TERRAIN_SHADER_H
