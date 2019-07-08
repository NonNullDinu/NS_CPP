#include "files.h"
#include <iostream>
using namespace std;
ifstream getGameDataFile(string *path)
{
    return ifstream(gameDataPath + "/" + (*path));
}

ifstream getGameDataFile(string path)
{
    return ifstream(gameDataPath + "/" + path);
}
