#ifndef STAR_H
#define STAR_H
#include "Planet.h"
class Star{
private:
    int current_planets;
    int next_id;
public:
    Planet **planets;
    Star();
    ~Star();
    long addPlanet();
    bool removePlanet(int);
    Planet getFurthest();
    Planet * getPlanet(int);
    void orbit();
    void printStarInfo();
    int getCurrentNumPlanets() {
      return this->current_planets;
    }
    //you may add any additional methodas you may need.
};
#endif
