#ifndef WATER_TILE_H
#define WATER_TILE_H

#include "VAO.h"
#include "terrain.h"
namespace WATER {
    const float TILE_SIZE = 2400.0;
    const int VERTEX_COUNT = (int) (32.0 * (TILE_SIZE / 600.0));
}
class water_tile
{
    public:
        water_tile();
        virtual ~water_tile();

    protected:

    private:
        VAO* model;
        float height;
        float x;
        float y;
        VAO* createModel(terrain *t);
};

#endif // WATER_TILE_H
