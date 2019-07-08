#ifndef FILES_H
#define FILES_H

#include <string>
#include <fstream>
using namespace std;

const static string gameDataPath = "/home/dinu/NS_CPP/gameData";

ifstream getGameDataFile(string *path);

ifstream getGameDataFile(string path);

#endif // FILES_H
