#include "../include/water_renderer.h"

water_renderer::water_renderer(water_shader *shader) : shader(shader)
{
}

water_renderer::~water_renderer()
{
    shader->start();

    shader->stop();
}
