#include "GU.h"

mat4 *projection(float FOV, float aspectRatio, float NEAR_PLANE, float FAR_PLANE)
{
    mat4 *projectionMatrix = new mat4;
    float y_scale = 1.0 / (float) tan(FOV / 2.0);
    float x_scale = y_scale / aspectRatio;
    float frustum_length = FAR_PLANE - NEAR_PLANE;
    projectionMatrix->m00 = x_scale;
    projectionMatrix->m11 = y_scale;
    projectionMatrix->m22 = -((FAR_PLANE + NEAR_PLANE) / frustum_length);
    projectionMatrix->m23 = -1;
    projectionMatrix->m32 = -((2 * NEAR_PLANE * FAR_PLANE) / frustum_length);
    projectionMatrix->m33 = 0;
    return projectionMatrix;
}

mat4 *createTransformtaion(entity *e)
{
    mat4 *tm = new mat4;
    tm->translate(e->GetPosition());
    tm->rotate(radians(e->GetRotX()), vec3(1, 0, 0));
    tm->rotate(radians(e->GetRotY()), vec3(0, 1, 0));
    tm->rotate(radians(e->GetRotZ()), vec3(0, 0, 1));
    tm->scale(vec3(e->GetScale(),e->GetScale(),e->GetScale()));
    return tm;
}

mat4 *createViewMatrix(camera *c)
{
    mat4 *vm = new mat4;
    vm->rotate(radians(c->GetRotX()), vec3(1,0,0));
    vm->rotate(radians(c->GetRotY()), vec3(0,1,0));
    vm->rotate(radians(c->GetRotZ()), vec3(0,0,1));
    vm->translate(-c->GetPosition());
    return vm;
}

#define hcPI (3.14159/180)

float radians(float ang)
{
    return ang * hcPI;
}

float barryCentric(vec3 p1, vec3 p2, vec3 p3, vec2 pos){
    float det = (p2.z - p3.z) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.z - p3.z);
    float l1 = ((p2.z - p3.z) * (pos.x - p3.x) + (p3.x - p2.x) * (pos.y - p3.z)) / det;
    float l2 = ((p3.z - p1.z) * (pos.x - p3.x) + (p1.x - p3.x) * (pos.y - p3.z)) / det;
	float l3 = 1.0f - l1 - l2;
	return l1 * p1.y + l2 * p2.y + l3 * p3.y;
}
