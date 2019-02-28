#ifndef STAR_H
#define STAR_H
#include "Planet.h"
#include "Vector.h"
#include "List.h"

class Star {      
	private:
        int curr_planets;
        int next_id;
	public:
        Planet ** planets;
        Star();
        ~Star();
        int addPlanet();
        bool removePlanet(int);
        Planet * getPlanet(int);
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets();
        int getMaxPlanets();
};

class Starvector {
    private:
        Vector star;
        int curr_planets;
    public:
        Starvector();
        ~Starvector();
        long addPlanet();
        bool removePlanet(long);
        Planet * getPlanet(long);
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
};

class Starlist {
    private:
        List star;
        int curr_planets;
    public:
        Starlist();
        ~Starlist();
        long addPlanet();
        bool removePlanet(long);
        Planet * getPlanet(long);
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
};
#endif
