#include "VAO.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>
using namespace std;

VAO::VAO(GLuint id, unordered_set<GLuint> *vbos, GLuint vertexCount) :
		id(id), vbos(vbos), vertexCount(vertexCount), boundSize(0), bound(NULL)
{
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &(this->id));
}

GLuint VAO::GetId()
{
    return this->id;
}

void VAO::bind(int size, int attributes[])
{
    glBindVertexArray(this->id);
    for(int i = 0; i < size; i++)
    {
        glEnableVertexAttribArray(attributes[i]);
    }
    this->bound = attributes;
    this->boundSize = size;
}

void VAO::unbind()
{
    for(int i = 0; i < this->boundSize; i++)
    {
        glDisableVertexAttribArray(this->bound[i]);
    }
    glBindVertexArray(0);
}

GLuint VAO::GetVertexCount()
{
    return this->vertexCount;
}
