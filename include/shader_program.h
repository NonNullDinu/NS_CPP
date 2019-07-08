#ifndef SHADER_PROGRAM_H_INCLUDED
#define SHADER_PROGRAM_H_INCLUDED

#include <string>

#include <GL/glew.h>
#include <GL/gl.h>
#include "uniform.h"

class shader_program
{
private:
    GLuint progId;
    GLuint vertexShaderId;
    GLuint fragmentShaderId;
protected:
public:
    shader_program(std::string vs, std::string fs);
    virtual ~shader_program();

    void start();
    void stop();

    int locateUniform(std::string name);
    void locateUniform(uniform *uniform);

    void loadUniformf(int loc, float v1);
    void loadUnifrom2f(int loc, float v1, float v2);
    void loadUnifrom3f(int loc, float v1, float v2, float v3);
    void loadUnifrom4f(int loc, float v1, float v2, float v3, float v4);
    void loadUniform1i(int loc, int v1);
    void loadUniformb(int loc, bool v1);
    void loadUniformMat4(int loc, float mat[16]);
};

#endif // SHADER_PROGRAM_H_INCLUDED
