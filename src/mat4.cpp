#include "mat4.h"

#include <cmath>

mat4::mat4()
{
    //ctor
}

mat4::~mat4()
{
    //dtor
}

vec4 mat4::operator*(vec4 a)
{
    return vec4(a.x * this->m00 + a.y * this->m10 + a.z * this->m20 + a.w * this->m30,
                a.x * this->m01 + a.y * this->m11 + a.z * this->m21 + a.w * this->m31,
                a.x * this->m02 + a.y * this->m12 + a.z * this->m22 + a.w * this->m32,
                a.x * this->m03 + a.y * this->m13 + a.z * this->m23 + a.w * this->m33);
}

void mat4::rotate(float angle, vec3 axis)
{
    float c = cos(angle);
    float s = sin(angle);
    float oneminusc = 1.0f - c;
    float xy = axis.x*axis.y;
    float yz = axis.y*axis.z;
    float xz = axis.x*axis.z;
    float xs = axis.x*s;
    float ys = axis.y*s;
    float zs = axis.z*s;

    float f00 = axis.x*axis.x*oneminusc+c;
    float f01 = xy*oneminusc+zs;
    float f02 = xz*oneminusc-ys;

    float f10 = xy*oneminusc-zs;
    float f11 = axis.y*axis.y*oneminusc+c;
    float f12 = yz*oneminusc+xs;

    float f20 = xz*oneminusc+ys;
    float f21 = yz*oneminusc-xs;
    float f22 = axis.z*axis.z*oneminusc+c;

    float t00 = this->m00 * f00 + this->m10 * f01 + this->m20 * f02;
    float t01 = this->m01 * f00 + this->m11 * f01 + this->m21 * f02;
    float t02 = this->m02 * f00 + this->m12 * f01 + this->m22 * f02;
    float t03 = this->m03 * f00 + this->m13 * f01 + this->m23 * f02;
    float t10 = this->m00 * f10 + this->m10 * f11 + this->m20 * f12;
    float t11 = this->m01 * f10 + this->m11 * f11 + this->m21 * f12;
    float t12 = this->m02 * f10 + this->m12 * f11 + this->m22 * f12;
    float t13 = this->m03 * f10 + this->m13 * f11 + this->m23 * f12;

    this->m20 = this->m00 * f20 + this->m10 * f21 + this->m20 * f22;
    this->m21 = this->m01 * f20 + this->m11 * f21 + this->m21 * f22;
    this->m22 = this->m02 * f20 + this->m12 * f21 + this->m22 * f22;
    this->m23 = this->m03 * f20 + this->m13 * f21 + this->m23 * f22;
    this->m00 = t00;
    this->m01 = t01;
    this->m02 = t02;
    this->m03 = t03;
    this->m10 = t10;
    this->m11 = t11;
    this->m12 = t12;
    this->m13 = t13;
}

void mat4::scale(vec3 vec)
{
    this->m00 = this->m00 * vec.x;
    this->m01 = this->m01 * vec.x;
    this->m02 = this->m02 * vec.x;
    this->m03 = this->m03 * vec.x;
    this->m10 = this->m10 * vec.y;
    this->m11 = this->m11 * vec.y;
    this->m12 = this->m12 * vec.y;
    this->m13 = this->m13 * vec.y;
    this->m20 = this->m20 * vec.z;
    this->m21 = this->m21 * vec.z;
    this->m22 = this->m22 * vec.z;
    this->m23 = this->m23 * vec.z;
}

void mat4::translate(vec3 vec)
{
    this->m30 += this->m00 * vec.x + this->m10 * vec.y + this->m20 * vec.z;
    this->m31 += this->m01 * vec.x + this->m11 * vec.y + this->m21 * vec.z;
    this->m32 += this->m02 * vec.x + this->m12 * vec.y + this->m22 * vec.z;
    this->m33 += this->m03 * vec.x + this->m13 * vec.y + this->m23 * vec.z;
}
