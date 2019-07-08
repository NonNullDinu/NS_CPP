#ifndef ENTITY_RENDERER_H
#define ENTITY_RENDERER_H

#include <unordered_map>
#include <vector>
#include "VAO.h"
#include "entity.h"
#include "static_shader.h"
using namespace std;

class entity_renderer
{
public:
    entity_renderer(static_shader*);
    virtual ~entity_renderer();
    void render(unordered_map<VAO*, vector<entity *> *, VAOHash, VAOEqual> *entities);
protected:

private:
    static_shader *shader;
};

#endif // ENTITY_RENDERER_H
