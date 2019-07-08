#include "shader_program.h"
#include <GL/glew.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "files.h"
#include "terrain_shader.h"
using namespace std;

shader_program::shader_program(string vs, string fs)
{
    this->progId = glCreateProgram();
    ifstream vsin = getGameDataFile(vs);
    ifstream fsin = getGameDataFile(fs);
    string sourcev = "", sourcef = "";
    string input;
    while(getline(vsin, input))
    {
        sourcev = sourcev + input + "\n";
    }
    while(getline(fsin, input))
    {
        sourcef = sourcef + input + "\n";
    }

    this->vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    this->fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    const char* csourcev = sourcev.c_str(), *csourcef = sourcef.c_str();
    GLint len = (GLint) sourcev.length();
    glShaderSource(this->vertexShaderId, 1, &csourcev, &len);
    len = (GLint) sourcef.length();
    glShaderSource(this->fragmentShaderId, 1, &csourcef, &len);

    glCompileShader(this->vertexShaderId);
    GLchar* buf = (GLchar*) malloc(300 * sizeof(GLchar));
    GLint param;
    glGetShaderiv(this->vertexShaderId, GL_COMPILE_STATUS, &param);
    if(param == GL_FALSE)
    {
        glGetShaderInfoLog(this->vertexShaderId, 300, &len, buf);
        cerr << vs << " failed to compile:\n" << (char*) buf << endl;
        exit(1);
    }

    glCompileShader(this->fragmentShaderId);
    glGetShaderiv(this->fragmentShaderId, GL_COMPILE_STATUS, &param);
    if(param == GL_FALSE)
    {
        glGetShaderInfoLog(this->fragmentShaderId, 300, &len, buf);
        cerr << fs << " failed to compile:\n" <<  (char*) buf << endl;
        exit(1);
    }

    glAttachShader(this->progId, this->vertexShaderId);
    glAttachShader(this->progId, this->fragmentShaderId);
    glLinkProgram(this->progId);
    glGetProgramiv(this->progId, GL_LINK_STATUS, &param);
    if(param == GL_FALSE)
    {
        glGetProgramInfoLog(this->progId, 300, &len, buf);
        cerr << this->progId << " failed to link:\n" <<  (char*) buf << endl;
        exit(1);
    }
    glValidateProgram(this->progId);
    glGetProgramiv(this->progId, GL_VALIDATE_STATUS, &param);
    if(param == GL_FALSE)
    {
        glGetProgramInfoLog(this->progId, 300, &len, buf);
        cerr << this->progId << " failed to validate:\n" <<  (char*) buf << endl;
        exit(1);
    }
}
shader_program::~shader_program()
{
    glDetachShader(this->progId, this->vertexShaderId);
    glDetachShader(this->progId, this->fragmentShaderId);
    glDeleteShader(this->vertexShaderId);
    glDeleteShader(this->fragmentShaderId);
    glDeleteProgram(this->progId);
}

void shader_program::start()
{
    glUseProgram(this->progId);
}
void shader_program::stop()
{
    glUseProgram(0);
}

int shader_program::locateUniform(string name)
{
    return glGetUniformLocation(this->progId, name.c_str());
}

void shader_program::loadUniformf(int loc, float v1)
{
    glUniform1f(loc, v1);
}
void shader_program::loadUnifrom2f(int loc, float v1, float v2)
{
    glUniform2f(loc, v1, v2);
}
void shader_program::loadUnifrom3f(int loc, float v1, float v2, float v3)
{
    glUniform3f(loc, v1, v2, v3);
}
void shader_program::loadUnifrom4f(int loc, float v1, float v2, float v3, float v4)
{
    glUniform4f(loc, v1, v2, v3, v4);
}
void shader_program::loadUniform1i(int loc, int v1)
{
    glUniform1i(loc, v1);
}

void shader_program::loadUniformb(int loc, bool v)
{
    loadUniform1i(loc, v ? 1 : 0);
}

void shader_program::loadUniformMat4(int loc, float mat[16])
{
    glUniformMatrix4fv(loc, 1, false, &mat[0]);
}

void shader_program::locateUniform(uniform *u)
{
    u->SetLocation(this->locateUniform(u->GetName()));
}
