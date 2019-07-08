#ifndef VEC3_H
#define VEC3_H

class vec3
{
public:
    vec3(float x, float y, float z);
    vec3(const vec3&);
    virtual ~vec3();
    float x, y, z;
    vec3 operator*(vec3 b);

    vec3 operator+(vec3 b);

    vec3 operator+(float b);

    vec3 operator-(float b);

    vec3 operator-(vec3 b);

    void operator+=(vec3 b);

    vec3 operator-();
protected:

private:
};

float dot(vec3 a, vec3 b);

#endif // VEC3_H
