#include "mywidget.h"
#include <QApplication>

#include <string>
#include <iostream>
#include <planet.h>
#include <planetutil.h>

using namespace std;

int similaritySearch(string text, string pattern, int maxNumberOfMismatches, int startPosition) {
    int patterncount = 0;
    int patternstart = -1;
    int remainingNumberOfMismatches = maxNumberOfMismatches;
    for(int i = startPosition; i < text.length(); i++) {
        if(text[i]==pattern[patterncount]){
            if(patternstart == -1){
                // Store the start of the pattern
                patternstart = i;
            }
            // char the same
            patterncount++;

            // check if end of pattern has been reached
            if(patterncount == pattern.length()) {
                return patternstart;
            }

        } else {
            // number does not match
            if(patternstart != -1) {
                // pattern search going on
                if(remainingNumberOfMismatches == 0){
                    // reset pattern if 0 reached
                    patternstart = -1;
                } else {
                    patterncount++;
                    remainingNumberOfMismatches--;
                }
            }
        }
    }

    return patternstart;
}




int main(int argc, char *argv[])
{

    // Aufgabe 1
    //cout << "Position: " << similaritySearch("GDFGHJDFFGJJGHJTYREYWERWETYDSGF", "DxG", 1, 0) << endl;

    //cout << "Position: " << similaritySearch("GDFGHJDFFGJJGHJTYREYWERWETYDSGF", "JDXXGJ", 1, 3) << endl;



    //QApplication a(argc, argv);
    //MyWidget w;
    //w.show();

    //return a.exec();


    // Aufgabe 3
    list<Planet> planets;

    Planet Planet1;
    Planet1.SetName("Erde");
    Planet1.SetX(50);
    Planet1.SetY(50);
    Planet1.SetZ(50);

    planets.push_back(Planet1);

    Planet Planet2;
    Planet2.SetName("Mond");
    Planet2.SetX(70);
    Planet2.SetY(70);
    Planet2.SetZ(70);

    planets.push_back(Planet2);

    Planet Planet3;
    Planet3.SetName("Sonne");
    Planet3.SetX(500);
    Planet3.SetY(500);
    Planet3.SetZ(500);

    planets.push_back(Planet3);

    cout << PlanetUtil::findNextPlanet(Planet2, planets) << endl;



}
