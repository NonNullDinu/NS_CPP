#ifndef WATER_RENDERER_H
#define WATER_RENDERER_H

#include "water_shader.h"

class water_renderer
{
    public:
        water_renderer(water_shader* shader);
        virtual ~water_renderer();

    protected:

    private:
        water_shader *shader;
};

#endif // WATER_RENDERER_H
