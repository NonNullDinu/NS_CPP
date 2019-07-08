#include "water_tile.h"
#include "VAOLoader.h"

water_tile::water_tile() : x(0), y(0), height(0), model(NULL)
{
    //ctor
}

water_tile::~water_tile()
{
    //dtor
}

VAO* water_tile::createModel(terrain *t){
    float *vao_pos = new float[(WATER::VERTEX_COUNT - 1) * (WATER::VERTEX_COUNT -1) * 12];
    char* vao_indicators = new char[(WATER::VERTEX_COUNT - 1) * (WATER::VERTEX_COUNT -1) * 24];
    int qp = 0;
    for(int z = 0; z < VERTEX_COUNT - 1; z++){
        for(int x = 0; x < VERTEX_COUNT - 1; x++){
            float xm = ((float) x / ((float) WATER::VERTEX_COUNT -1) - 0.5) * 2.0 * WATER::TILE_SIZE;
            float zm = ((float) z / ((float) WATER::VERTEX_COUNT -1) - 0.5) * 2.0 * WATER::TILE_SIZE;
            float xM = (((float) x+1) / ((float) WATER::VERTEX_COUNT -1) - 0.5) * 2.0 * WATER::TILE_SIZE;
            float zM = (((float) z + 1) / ((float) WATER::VERTEX_COUNT -1) - 0.5) * 2.0 * WATER::TILE_SIZE;
            vao_pos[qp*12] = xm;
            vao_pos[qp*12+1] = zm;

            vao_pos[qp*12+2] = xm;
            vao_pos[qp * 12 + 3] = zM;

            vao_pos[qp * 12 + 4] = xM;
            vao_pos[qp * 12 + 5] = zm;

            vao_pos[qp * 12 + 6] = xM;
            vao_pos[qp * 12 + 7] = zm;

            vao_pos[qp * 12 + 8] = xm;
            vao_pos[qp * 12 + 9] = zM;

            vao_pos[qp * 12 + 10] = xM;
            vao_pos[qp * 12 + 11] = zM;

            vao_indicators[qp * 24] = 0;
            vao_indicators[qp * 24+1] = 1;
            vao_indicators[qp * 24+2] = 1;
            vao_indicators[qp * 24+3] = 0;

            vao_indicators[qp * 24+4] = 0;
            vao_indicators[qp * 24+5] = -1;
            vao_indicators[qp * 24+6] = 1;
            vao_indicators[qp * 24+7] = -1;

            vao_indicators[qp * 24+8] = -1;
            vao_indicators[qp * 24+9] = 0;
            vao_indicators[qp * 24+10] = -1;
            vao_indicators[qp * 24+11] = 1;

            vao_indicators[qp * 24+12] = -1;
            vao_indicators[qp * 24+13] = 1;
            vao_indicators[qp * 24+14] = 0;
            vao_indicators[qp * 24+15] = 1;

            vao_indicators[qp * 24+16] = 1;
            vao_indicators[qp * 24+17] = -1;
            vao_indicators[qp * 24+18] = 1;
            vao_indicators[qp * 24+19] = 0;

            vao_indicators[qp * 24+20] = 0;
            vao_indicators[qp * 24+21] = -1;
            vao_indicators[qp * 24+22] = -1;
            vao_indicators[qp * 24+23] = 0;

            qp++;
        }
    }
    VBO_DATA *vbo = new VBO_DATA[2];
    vbo[0].init((WATER::VERTEX_COUNT - 1) * (WATER::VERTEX_COUNT -1) * 12, vao_pos);
    vbo[1].init((WATER::VERTEX_COUNT - 1) * (WATER::VERTEX_COUNT -1) * 24, vao_indicators);
    vbo[0].addInfo(new INFO(GL_STATIC_DRAW, 0, 2, false));
    vbo[1].addInfo(new INFO(GL_STATIC_DRAW, 1, 2, false));
    return GL::vao_make(2, vbo);
}
