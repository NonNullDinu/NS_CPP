#ifndef ENTITY_H
#define ENTITY_H

#include "VAO.h"
#include "vec3.h"

class entity
{
public:
    entity(VAO*, vec3);
    virtual ~entity();
    VAO* GetModel();
    vec3 GetPosition();
    float GetRotX();
    float GetRotY();
    float GetRotZ();
    float GetScale();
    void addToPosition(vec3 d);
    void rotate(vec3 d);

protected:

private:
    VAO *model;
    vec3 position;
    float rotx=0, roty=0, rotz=0, scale=1;
};

#endif // ENTITY_H
