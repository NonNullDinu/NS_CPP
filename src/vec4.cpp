#include "vec4.h"

vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

vec4::~vec4() {}

vec4 vec4::operator*(float a)
{
    return vec4(this->x * a, this->y * a, this->z * a, this->w * a);
}
vec4 vec4::operator+(float b)
{
    return vec4(this->x + b, this->y + b, this->z + b, this->w + b);
}
vec4 vec4::operator-(float b)
{
    return vec4(this->x - b, this->y - b, this->z - b, this->w - b);
}
vec4 vec4::operator-(vec4 b)
{
    return vec4(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);
}
vec4 vec4::operator+(vec4 b)
{
    return vec4(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);
}
