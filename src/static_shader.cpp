#include "static_shader.h"
static_shader::static_shader(mat4 *projection) : shader_program("shaders/standard/vertexShader.glsl", "shaders/standard/fragmentShader.glsl"), projectionMatrixu("projectionMatrix"), transformationMatrixu("transformationMatrix"), viewMatrixu("viewMatrix")
{
    start();
    shader_program::locateUniform(&projectionMatrixu);
    shader_program::locateUniform(&transformationMatrixu);
    shader_program::locateUniform(&viewMatrixu);
    this->projectionMatrixu.load(projection);
    stop();
}

static_shader::~static_shader() {}
