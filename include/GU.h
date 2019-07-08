#ifndef GU_H
#define GU_H

#include <math.h>
#include "mat4.h"
#include "entity.h"
#include "camera.h"
#include "vec2.h"
#include "vec3.h"

namespace GameUtil
{
static float delta=0;
}

mat4 *projection(float fov, float ratio, float NEAR_PLANE, float FAR_PLANE);

mat4 *createTransformtaion(entity *e);

mat4 *createViewMatrix(camera *c);

float radians(float ang);

float barryCentric(vec3 a, vec3 b, vec3 c, vec2 pos);

#endif // GU_H
