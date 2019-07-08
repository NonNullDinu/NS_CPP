#include "terrain_shader.h"

#include <iostream>
using namespace std;

terrain_shader::terrain_shader(mat4 *proj) : shader_program::shader_program("shaders/terrain/terrainVertex.glsl", "shaders/terrain/terrainFragment.glsl"), viewMatrixu("viewMatrix"), projectionMatrixu("projectionMatrix"), x("x"), z("z")
{
    this->start();
    shader_program::locateUniform(&viewMatrixu);
    shader_program::locateUniform(&projectionMatrixu);
    shader_program::locateUniform(&x);
    shader_program::locateUniform(&z);
    this->projectionMatrixu.load(proj);
    this->postlink();
    this->stop();
}

terrain_shader::~terrain_shader()
{
    glDeleteBuffers(1, &(this->colorsBuffer));
}

const int VERTEX_COUNT = 512;

void terrain_shader::postlink() {
    glGenBuffers(1, &(this->colorsBuffer));
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, this->colorsBuffer);
    float *d = new float[(VERTEX_COUNT - 1) * (VERTEX_COUNT - 1)];
    for(int i = 0; i < (VERTEX_COUNT - 1) * (VERTEX_COUNT - 1); i++)
        d[i] = 0.0;
    glBufferData(GL_SHADER_STORAGE_BUFFER, 4 * (VERTEX_COUNT - 1) * (VERTEX_COUNT - 1), d, GL_STATIC_DRAW);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, colorsBuffer);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}
