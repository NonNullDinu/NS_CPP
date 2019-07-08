#include "uniform.h"

uniform::uniform(string name)
{
    this->name = name;
}

uniform::~uniform() {}

int uniform::GetLoc()
{
    return this->loc;
}

string uniform::GetName()
{
    return this->name;
}

void uniform::SetLocation(int loc)
{
    this->loc = loc;
}
