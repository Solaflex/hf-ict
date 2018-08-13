#ifndef PLANETUTIL_H
#define PLANETUTIL_H

#include <planet.h>
#include <list>

class PlanetUtil
{
public:
    PlanetUtil();
    static string findNextPlanet(Planet planet, list<Planet> planets);
};

#endif // PLANETUTIL_H
