#include <QCoreApplication>
#include <iostream>
#include <vector>


using namespace std;


struct Point {
    int x;
    int y;
};

vector<Point> findPoints(vector<Point> points, Point A, Point B, Point C, Point D) {
    vector<Point> result;
    Point NearestA;
    Point NearestB;
    Point NearestC;
    Point NearestD;
    int distance, pointdistance;

    // A
    distance = 0;
    pointdistance = 0;
    for(Point p : points) {
        pointdistance = sqrt((abs(p.x - A.x)*2) + (abs(p.y - A.y)*2));
        if(pointdistance <= distance || distance == 0){
            NearestA = p;
            distance = pointdistance;
        }
    }

    // B
    distance = 0;
    pointdistance = 0;
    for(Point p : points) {
        pointdistance = sqrt((abs(p.x - B.x)*2) + (abs(p.y - B.y)*2));
        if(pointdistance < distance || distance == 0){
            NearestB = p;
            distance = pointdistance;
        }
    }

    // C
    distance = 0;
    pointdistance = 0;
    for(Point p : points) {
        pointdistance = sqrt((abs(p.x - C.x)*2) + (abs(p.y - C.y)*2));
        if(pointdistance <= distance || distance == 0){
            NearestC = p;
            distance = pointdistance;
        }
    }

    // D
    distance = 0;
    pointdistance = 0;
    for(Point p : points) {
        pointdistance = sqrt((abs(p.x - D.x)*2) + (abs(p.y - D.y)*2));
        if(pointdistance <= distance || distance == 0){
            NearestD = p;
            distance = pointdistance;
        }
    }



    result.push_back(NearestA);
    result.push_back(NearestB);
    result.push_back(NearestC);
    result.push_back(NearestD);


    return result;
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<Point> MyPoints;
    Point RandomPoint;
    RandomPoint.x = 60;
    RandomPoint.y = 60;
    MyPoints.push_back(RandomPoint);

    RandomPoint.x = 600;
    RandomPoint.y = 600;
    MyPoints.push_back(RandomPoint);

    RandomPoint.x = 805;
    RandomPoint.y = 800;
    MyPoints.push_back(RandomPoint);

    RandomPoint.x = 810;
    RandomPoint.y = 810;
    MyPoints.push_back(RandomPoint);

    RandomPoint.x = 750;
    RandomPoint.y = 750;
    MyPoints.push_back(RandomPoint);

    Point A;
    A.x = 50;
    A.y = 50;

    Point B;
    B.x = 110;
    B.y = 110;

    Point C;
    C.x = 500;
    C.y = 500;

    Point D;
    D.x = 800;
    D.y = 800;

    vector<Point> result = findPoints(MyPoints, A, B, C, D);


    return a.exec();



}
