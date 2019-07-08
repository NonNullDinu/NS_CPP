#ifndef UNIFORM_FLOAT_H
#define UNIFORM_FLOAT_H

#include "uniform.h"

class uniform_float : public uniform
{
public:
    uniform_float(string name);
    virtual ~uniform_float();
    void load(float v);
protected:

private:
};

#endif // UNIFORM_FLOAT_H
