#ifndef MAT4_H
#define MAT4_H

#include "vec3.h"
#include "vec4.h"

class mat4
{
public:
    mat4();
    virtual ~mat4();
    float m00=1, m01=0, m02=0, m03=0,
          m10=0, m11=1, m12=0, m13=0,
          m20=0, m21=0, m22=1, m23=0,
          m30=0, m31=0, m32=0, m33=1;
    vec4 operator*(vec4 a);

    void rotate(float angle, vec3 axis);
    void scale(vec3 scale);
    void translate(vec3 vec);
protected:

private:
};

#endif // MAT4_H
