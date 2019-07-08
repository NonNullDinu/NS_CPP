#include "terrain_renderer.h"

#include <GL/glew.h>

terrain_renderer::terrain_renderer(terrain_shader *shader)
{
    this->shader = shader;
}

terrain_renderer::~terrain_renderer()
{
    //dtor
}

void terrain_renderer::render(terrain *t)
{
    int at[] = {0,1};
    t->GetModel()->bind(2, at);
    this->shader->x.load(t->GetX());
    this->shader->z.load(t->GetZ());
    glDrawElements(GL_TRIANGLES, t->GetModel()->GetVertexCount(), GL_UNSIGNED_INT, nullptr);
    t->GetModel()->unbind();
}
