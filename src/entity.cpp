#include "entity.h"

entity::entity(VAO* model, vec3 p) : model(model), position(p) {}

entity::~entity() {}

VAO* entity::GetModel()
{
    return this->model;
}

vec3 entity::GetPosition()
{
    return this->position;
}

float entity::GetRotX()
{
    return this->rotx;
}
float entity::GetRotY()
{
    return this->roty;
}
float entity::GetRotZ()
{
    return this->rotz;
}
float entity::GetScale()
{
    return this->scale;
}

void entity::addToPosition(vec3 d)
{
    this->position += d;
}

void entity::rotate(vec3 d)
{
    this->rotx+=d.x;
    this->roty+=d.y;
    this->rotz+=d.z;
}
