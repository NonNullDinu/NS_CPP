#include "vec3.h"

vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}
vec3::vec3(const vec3& src) : vec3(src.x, src.y, src.z) {}
vec3::~vec3() {}

float dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 vec3::operator*(vec3 b)
{
    return vec3(this->y * b.z - this->z * b.y, this->z * b.x - this->x * b.z, this->x * b.y - this->y * b.x);
}

vec3 vec3::operator+(vec3 b)
{
    return vec3(this->x + b.x, this->y + b.y, this->z + b.z);
}

vec3 vec3::operator+(float b)
{
    return vec3(this->x + b, this->y + b, this->z + b);
}

vec3 vec3::operator-(float b)
{
    return vec3(this->x - b, this->y - b, this->z - b);
}

vec3 vec3::operator-(vec3 b)
{
    return vec3(this->x - b.x, this->y - b.y, this->z - b.z);
}

void vec3::operator+=(vec3 b)
{
    this->x+=b.x;
    this->y+=b.y;
    this->z+=b.z;
}

vec3 vec3::operator-()
{
    return vec3(-this->x, -this->y, -this->z);
}
