#ifndef MASTER_RENDERER_H
#define MASTER_RENDERER_H

#include <vector>
#include <unordered_map>

#include "entity_renderer.h"
#include "terrain_renderer.h"
#include "entity.h"
#include "terrain.h"
#include "VAO.h"
#include "static_shader.h"
#include "camera.h"
#include "terrain_shader.h"
using namespace std;

class master_renderer
{
public:
    master_renderer();
    virtual ~master_renderer();

    void prepare();
    void render(camera* c);
    void renderScene(camera* c, terrain* t, vector<entity*>* e);
    void process(entity *e);
    void process(terrain *t);

private:
    entity_renderer *e_renderer;
    terrain_renderer *t_renderer;
    unordered_map<VAO*, vector<entity *> *, VAOHash, VAOEqual> *entities;
    terrain *t;
    static_shader *shader;
    terrain_shader *t_shader;
    mat4 *projectionMatrix;
};

#endif // MASTER_RENDERER_H
