#ifndef STAR_LH
#define STAR_LH
#include "Planet.h"

class Starlist{
private:
    int current_planets;
    int next_id;
public:
    Starlist();
    ~Starlist();
    long addPlanet();
    bool removePlanet(int);
    Planet * getPlanet(int);
    void orbit();
    void printStarInfo();
    unsigned int getCurrentNumPlanets() {
      return this->current_planets;
    }
}
#endif
