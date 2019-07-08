#include "entity_renderer.h"
#include <iostream>
#include "mat4.h"
#include "GU.h"
using namespace std;
entity_renderer::entity_renderer(static_shader* shader)
{
    this->shader = shader;
}

entity_renderer::~entity_renderer()
{
    // delete this->shader;
}

void entity_renderer::render(unordered_map<VAO*, vector<entity *> *, VAOHash, VAOEqual> *entities)
{
    static int atr[] = {0};
    for(unordered_map<VAO*, vector<entity *> *, VAOHash, VAOEqual>::iterator itr = entities->begin(); itr != entities->end(); itr++)
    {
        VAO* vao = (*itr).first;
        vector<entity*> *vec = (*itr).second;
        vao->bind(1, atr);
        for(vector<entity*>::iterator itv = vec->begin(); itv != vec->end(); itv++)
        {
            this->shader->transformationMatrixu.load(createTransformtaion(*itv));
            glDrawArrays(GL_TRIANGLES, 0, vao->GetVertexCount());
        }
        vao->unbind();
    }
}
