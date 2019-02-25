#ifndef STAR_VH
#define STAR_VH
#include "Planet.h"

class StarVector{
private:
    int current_planets;
    int next_id;
public:
    Planet **planets;
    StarVector();
    ~StarVector();
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
