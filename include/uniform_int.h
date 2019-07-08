#ifndef UNIFORM_INT_H
#define UNIFORM_INT_H

#include "uniform.h"
#include <string>
using namespace std;

class uniform_int : public uniform
{
public:
    uniform_int(string name);
    virtual ~uniform_int();
    void load(int v);
protected:

private:
};

#endif // UNIFORM_INT_H
