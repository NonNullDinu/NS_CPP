#include "camera.h"
#include <iostream>
using namespace std;

camera::camera() : position(vec3(0,0,0)), rotx(0), roty(0), rotz(0)
{
    //ctor
}

camera::~camera()
{
    //dtor
}

float camera::GetRotX()
{
    return this->rotx;
}
float camera::GetRotY()
{
    return this->roty;
}
float camera::GetRotZ()
{
    return this->rotz;
}
vec3 camera::GetPosition()
{
    return this->position;
}

void camera::rotate(float dx, float dy, float dz)
{
    this->rotx += dx;
    this->roty += dy;
    this->rotz += dz;
}
void camera::move(float dx, float dy, float dz)
{
    this->position+=vec3(dx,dy,dz);
}

void camera::update(int c, int x, int y, float delta){
    if((c & 1))
        this->rotate(-80.0 * delta,0,0);
    if((c & 2))
        this->rotate(80.0 * delta,0,0);

    if((c & 4))
        this->rotate(0, -80.0 * delta, 0);
    if((c & 8))
        this->rotate(0, 80.0 * delta, 0);

    if((c & 16))
        this->move(0, 0, -50.0 * delta);

    if((c & 32))
        this->move(-50.0 * delta, 0, 0);

    if((c & 64))
        this->move(0, 0, 50.0 * delta);

    if((c & 128))
        this->move(50.0 * delta, 0, 0);
}
