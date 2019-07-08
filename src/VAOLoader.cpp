#include "VAOLoader.h"

#include <unordered_set>
#include <iostream>
using namespace std;

namespace GL
{
VAO* vao_make(int len, VBO_DATA *data)
{
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLuint vbo;
    unordered_set<GLuint> *vbos = new unordered_set<GLuint>();

    GLuint vc = 0;
    for(int i = 0; i < len; i++)
    {
        glGenBuffers(1, &vbo);
        data[i].put_data_in_vbo(vbo);
        if(data[i].GetInfo()->isIndices)
            vc = (GLuint) data[i].GetLen();
        vbos->insert(vbo);
    }
    if(vc == 0)
        vc = data[0].GetLen() / data[0].GetInfo()->dimensions;
    glBindVertexArray(0);
    delete[] data;
    return new VAO(vao, vbos, vc);
}
}
