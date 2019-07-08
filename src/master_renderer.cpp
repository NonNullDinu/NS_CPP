#include "master_renderer.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <iostream>
#include "GU.h"
using namespace std;

master_renderer::master_renderer() : t(NULL)
{
    this->projectionMatrix = projection(70.0, 1200.0/720.0, 0.1, 1000.0);
    this->shader = new static_shader(this->projectionMatrix);
    this->t_shader = new terrain_shader(this->projectionMatrix);
    this->entities = new unordered_map<VAO*, vector<entity *> *, VAOHash, VAOEqual>();
    this->e_renderer = new entity_renderer(this->shader);
    this->t_renderer = new terrain_renderer(this->t_shader);
}

master_renderer::~master_renderer()
{
    delete this->projectionMatrix;
    delete shader;
    delete t_shader;
    delete entities;
    delete e_renderer;
    delete t_renderer;
}


void master_renderer::prepare()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void master_renderer::render(camera *c)
{
    this->shader->start();
    mat4 *view = createViewMatrix(c);
    this->shader->viewMatrixu.load(view);
    this->e_renderer->render(this->entities);
    this->shader->stop();
    this->t_shader->start();
    this->t_shader->viewMatrixu.load(view);
    this->t_renderer->render(this->t);
    this->t = nullptr;
    this->entities->clear();
}

void master_renderer::renderScene(camera *c, terrain* t, vector<entity *> *e)
{
    process(t);
    for(vector<entity*>::iterator itr = e->begin(); itr != e->end(); itr++)
    {
        process(*itr);
    }
    render(c);
}

void master_renderer::process(entity *e)
{
    vector<entity*>* vec;
    try
    {
        vec = this->entities->at(e->GetModel());
    }
    catch (const std::out_of_range& err)
    {
        vec = new vector<entity *>();
        this->entities->insert({e->GetModel(), vec});
    }
    vec->push_back(e);
}

void master_renderer::process(terrain *t)
{
    this->t = t;
}
