#ifndef TERRAIN_H
#define TERRAIN_H

#include "VAO.h"
#include "heights_generator.h"

const float SIZE = 4800.0;
const int VERTEX_COUNT = 512;

class terrain
{
public:
    terrain();
    virtual ~terrain();
    VAO *GetModel();
    void MakeModel();
    float GetX();
    float GetZ();
    float getHeight(float x, float z);
protected:

private:
    VAO *model;
    heights_generator *heightsGenerator;
    float* heights;
    float m_getHeight(int x, int z);
    float x = -SIZE/2.0, z=-SIZE/2.0;
};

#endif // TERRAIN_H
