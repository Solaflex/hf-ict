#ifndef PLANET_H
#define PLANET_H

#include <string>

using namespace std;


class Planet
{
public:
    Planet();
    string name;
    int x,y,z;
    int distance;
public:
    void SetX(int x);
    void SetY(int y);
    void SetZ(int z);
    void SetName(string name);

    int GetX();
    int GetY();
    int GetZ();
    string GetName();
    void setDistance(int distance);
    int getDistance();
};

#endif // PLANET_H
