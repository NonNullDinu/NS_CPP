#ifndef UNIFORM_H
#define UNIFORM_H

#include <string>
using namespace std;

class uniform
{
public:
    uniform(string name);
    virtual ~uniform();
    int GetLoc();
    void SetLocation(int loc);
    string GetName();
protected:
    int loc=-1;
private:
    string name;
};

#endif // UNIFORM_H
