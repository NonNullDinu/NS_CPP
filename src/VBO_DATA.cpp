#include "VBO_DATA.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>
using namespace std;

INFO::INFO(int usage, int vbo_index, int dimensions, bool isIndices) : usage(usage), vbo_index(vbo_index), dimensions(dimensions), isIndices(isIndices) {}

VBO_DATA::VBO_DATA() : info(NULL), datai(NULL), dataf(NULL), datab(NULL), len(0)
{
    this->type = -1;
}

VBO_DATA::VBO_DATA(int len, int* data) : datab(NULL), dataf(NULL), info(NULL)
{
    this->len = len;
    this->type = 0;
    this->datai = data;
}

VBO_DATA::VBO_DATA(int len, char* data): datai(NULL), dataf(NULL), info(NULL)
{
    this->len = len;
    this->type = 1;
    this->datab = data;
}

VBO_DATA::VBO_DATA(int len, float* data) : datai(NULL), datab(NULL), info(NULL)
{
    this->len = len;
    this->type = 2;
    this->dataf = data;
}

VBO_DATA::~VBO_DATA()
{
    switch(this->type)
    {
    case 0:
        delete[] datai;
        break;
    case 1:
        delete[] datab;
        break;
    case 2:
        delete[] dataf;
        break;
    }
}

void VBO_DATA::put_data_in_vbo(GLuint vbo)
{
    if(this->type == -1)
        throw 1;
    int buf = this->info->isIndices ? GL_ELEMENT_ARRAY_BUFFER : GL_ARRAY_BUFFER;
    glBindBuffer(buf, vbo);
    glBufferData(buf, this->len * (this->type == 0 ? sizeof(int) : (this->type == 1 ? sizeof(char) : sizeof(float))), this->type == 0 ? (void*)(this->datai) : (this->type == 1 ? (void*)(this->datab) : (void*)(this->dataf)), this->info->usage);
    if(!this->info->isIndices)
    {
        glVertexAttribPointer(this->info->vbo_index, this->info->dimensions, (this->type == 0 ? GL_INT : (this->type == 1 ? GL_BYTE : GL_FLOAT)), false, 0, 0);
        glBindBuffer(buf, 0);
    }
}

void VBO_DATA::addInfo(INFO* info)
{
    this->info = info;
}

INFO* VBO_DATA::GetInfo()
{
    return this->info;
}

int VBO_DATA::GetLen()
{
    return this->len;
}

void VBO_DATA::init(int len, int* data)
{
    this->len = len;
    this->type = 0;
    this->datai = data;
}


void VBO_DATA::init(int len, char* data)
{
    this->len = len;
    this->type = 1;
    this->datab = data;
}

void VBO_DATA::init(int len, float* data)
{
    this->len = len;
    this->type = 2;
    this->dataf = data;
}
