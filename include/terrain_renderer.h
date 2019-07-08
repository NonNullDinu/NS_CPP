#ifndef TERRAIN_RENDERER_H
#define TERRAIN_RENDERER_H

#include "terrain.h"
#include "terrain_shader.h"

class terrain_renderer
{
public:
    terrain_renderer(terrain_shader *shader);
    virtual ~terrain_renderer();
    void render(terrain *t);
protected:

private:
    terrain_shader *shader;
};

#endif // TERRAIN_RENDERER_H
