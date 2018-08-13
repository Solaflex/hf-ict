#include "planetutil.h"
#include <list>
#include <iostream>

using namespace std;

PlanetUtil::PlanetUtil()
{

}



string PlanetUtil::findNextPlanet(Planet planet, list<Planet> planets){
    int distance;
    Planet result;
    for (Planet p : planets) {
        cout << "name: " << planet.GetName() << "/" << p.GetName();
        //cout << " x: " << planet.getX() << "/" << p.getX();
        //cout << " y: " << planet.getY() << "/" << p.getY();
        //cout << " z: " << planet.getZ() << "/" << p.getZ() << endl;
        distance = 0;
        distance += planet.GetX() - p.GetX();
        distance += planet.GetY() - p.GetY();
        distance += planet.GetZ() - p.GetZ();
        cout << endl;
        if (distance < 0) distance *= -1;
        p.setDistance(distance);
        cout << distance << endl;
        if (distance != 0 && result.getDistance() > distance) {
            result = p;
        }
    }
    return result.GetName();

}
