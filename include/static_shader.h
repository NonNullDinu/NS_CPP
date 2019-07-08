#ifndef STATIC_SHADER_H_INCLUDED
#define STATIC_SHADER_H_INCLUDED

#include "shader_program.h"
#include "mat4.h"
#include "uniform_mat4.h"

class static_shader : public shader_program
{
public:
    static_shader(mat4 *projection);
    virtual ~static_shader();
    uniform_mat4 projectionMatrixu;
    uniform_mat4 transformationMatrixu;
    uniform_mat4 viewMatrixu;

protected:
private:
};

#endif // STATIC_SHADER_H_INCLUDED
