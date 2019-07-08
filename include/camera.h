#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"

class camera
{
public:
    camera();
    virtual ~camera();
    vec3 GetPosition();
    float GetRotX();
    float GetRotY();
    float GetRotZ();
    void rotate(float dx, float dy, float dz);
    void move(float dx, float dy, float dz);
    void update(int controls, int mx, int my, float delta);
protected:

private:
    vec3 position;
    float rotx, roty, rotz;
};

#endif // CAMERA_H
