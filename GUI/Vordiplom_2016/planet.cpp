#include "planet.h"

Planet::Planet()
{

}

void Planet::SetX(int x){
    this->x = x;
}
void Planet::SetY(int y){
    this->y = y;
}
void Planet::SetZ(int z){
    this->z = z;
}

void Planet::SetName(string name){
    this->name = name;
}

int Planet::GetX(){
    return this->x;
}
int Planet::GetY(){
    return this->y;
}
int Planet::GetZ(){
    return this->z;
}
string Planet::GetName(){
    return this->name;
}

void Planet::setDistance(int distance) {
    this->distance = distance;
}

int Planet::getDistance() {
    return distance;
}
