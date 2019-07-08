#ifndef VEC4_H
#define VEC4_H

class vec4
{
public:
    vec4(float x, float y, float z, float w);
    vec4(const vec4&);
    virtual ~vec4();
    float x, y, z, w;

    vec4 operator+(vec4 b);

    vec4 operator+(float b);

    vec4 operator-(float b);

    vec4 operator-(vec4 b);

    vec4 operator*(float a);
protected:

private:
};

#endif // VEC4_H
