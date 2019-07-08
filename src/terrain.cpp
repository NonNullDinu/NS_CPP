#include "terrain.h"

#include <stdlib.h>
#include <iostream>
#include "VBO_DATA.h"
#include "VAOLoader.h"
#include <cmath>
#include "vec3.h"
#include "vec2.h"
#include "GU.h"
using namespace std;

terrain::terrain()
{
    this->heightsGenerator = new heights_generator();
    this->MakeModel();
    delete heightsGenerator;
}

terrain::~terrain()
{
    delete model;
}

VAO* terrain::GetModel()
{
    return this->model;
}

void terrain::MakeModel()
{
    int count = VERTEX_COUNT * VERTEX_COUNT;
    this->heights = new float[count];
    for(int i = 0; i < count; ++i)
        this->heights[i] = -100.0;
    float *vertices = new float[count * 3];
    float *colors = new float[count * 3];
    int vp = 0;
    for(int z = 0; z < VERTEX_COUNT; z++)
    {
        for(int x = 0; x < VERTEX_COUNT; x++)
        {
            vertices[3*vp] = ((float) x / ((float) VERTEX_COUNT - 1)) * SIZE;
            vertices[3*vp+1] = m_getHeight(x, z);
            vertices[3*vp+2] = ((float) z / ((float) VERTEX_COUNT - 1)) * SIZE;
            colors[3*vp] = 0.71;
            colors[3*vp+1] = 0.478;
            colors[3*vp+2] = 0.0;
            vp++;
        }
    }
    int *indices = new int[6 * (VERTEX_COUNT - 1) * (VERTEX_COUNT-1)];
    int p = 0;
    for(int z = 0; z < VERTEX_COUNT-1; z++)
    {
        for(int x = 0; x < VERTEX_COUNT-1; x++)
        {
            int topLeft = z*VERTEX_COUNT + x;
            int topRight = topLeft + 1;
            int bottomLeft = (z+1) * VERTEX_COUNT + x;
            int bottomRight = bottomLeft + 1;
            if((x + z)%2 == 0)
            {
                indices[p++] = topLeft;
                indices[p++] = bottomLeft;
                indices[p++] = bottomRight;

                indices[p++] = bottomRight;
                indices[p++] = topLeft;
                indices[p++] = topRight;
            }
            else
            {
                indices[p++] = topLeft;
                indices[p++] = bottomLeft;
                indices[p++] = topRight;

                indices[p++] = bottomLeft;
                indices[p++] = bottomRight;
                indices[p++] = topRight;
            }
        }
    }
    VBO_DATA *vbo_data = new VBO_DATA[3];

    vbo_data[0].init(3*count, vertices);
    vbo_data[0].addInfo(new INFO(GL_STATIC_DRAW, 0, 3, false));
    vbo_data[1].init(3*count, colors);
    vbo_data[1].addInfo(new INFO(GL_STATIC_DRAW, 1, 3, false));
    vbo_data[2].init(6 * (VERTEX_COUNT - 1) * (VERTEX_COUNT-1), indices);
    vbo_data[2].addInfo(new INFO(GL_STATIC_DRAW, -1, -1, true));
    this->model = GL::vao_make(3, vbo_data);
}

float terrain::m_getHeight(int x, int z)
{
    if(this->heights[z*VERTEX_COUNT + x] == -100.0)
    {
        float h = this->heightsGenerator->getHeight(x,z);
        heights[z*VERTEX_COUNT+x] = h;
        return h;
    }
    else
        return this->heights[z*VERTEX_COUNT + x];
}

float terrain::GetX()
{
    return this->x;
}

float terrain::GetZ()
{
    return this->z;
}

float modf(float a, float b)
{
    return a - floor(a/b) * b;
}

float terrain::getHeight(float x, float z)
{
    float t_x = x - this->x;
    float t_z = z - this->z;
    float gridSquareSize = SIZE / ((float) VERTEX_COUNT - 1);
    int gridX = (int) floor(t_x / gridSquareSize);
    int gridZ = (int) floor(t_z / gridSquareSize);
    if(gridX >= VERTEX_COUNT - 1 || gridZ >= VERTEX_COUNT - 1 || gridX < 0 || gridZ < 0)
        return 0;
    float xCoord = modf(t_x, gridSquareSize) / gridSquareSize;
    float zCoord = modf(t_z, gridSquareSize) / gridSquareSize;
    float answer;
    if(xCoord <= (1 - zCoord))
    {
        answer = barryCentric(vec3(0, this->m_getHeight(gridX, gridZ), 0), vec3(1, this->m_getHeight(gridX + 1,gridZ), 0), vec3(0, this->m_getHeight(gridX, gridZ + 1), 1), vec2(xCoord, zCoord));
    }
    else
        answer = barryCentric(vec3(1,this->m_getHeight(gridX+1, gridZ), 0), vec3(1, this->m_getHeight(gridX+1, gridZ+1),1), vec3(0, this->m_getHeight(gridX, gridZ+1), 1), vec2(xCoord, zCoord));
    return answer;
}
