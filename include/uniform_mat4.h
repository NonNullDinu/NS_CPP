#ifndef UNIFORM_MAT4_H
#define UNIFORM_MAT4_H

#include "uniform.h"
#include "mat4.h"

class uniform_mat4 : public uniform
{
public:
    uniform_mat4(string name);
    virtual ~uniform_mat4();
    void load(mat4 *mat);
protected:

private:
};

#endif // UNIFORM_MAT4_H
