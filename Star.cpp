#include "Star.h"
#include <iostream>

using namespace std;

Star::Star() {
    this->curr_planets = 0;
    this->planets=NULL;
    this->next_id=0;
}

Star::~Star() {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++)
        delete planets[i];
    delete[] planets;
}

int Star::addPlanet() {
    int curr_planets = this->getCurrentNumPlanets();
    Planet ** p = new Planet*[curr_planets+1];
    for(int i=0; i<curr_planets; i++) {
        p[i] = this->planets[i];
    }
    int id = rand() % 100000;
    Planet *new_planet = new Planet(rand() % 3000);
    p[curr_planets] = new_planet;
    this->curr_planets++;
    delete[] planets;
    this->planets = p;
    return id;
}

Planet * Star::getPlanet(int id) {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        if(id==planets[i]->getID()) {
            return planets[i];
        }
    }
    return NULL;
}

bool Star::removePlanet(int del_id) {
    int curr_planets = this->getCurrentNumPlanets();
    int j = 0;
    if(getPlanet(del_id)==NULL) {
        return false;
    }
    Planet ** p = new Planet*[curr_planets-1];
    for(int i=0; i<curr_planets; i++) {
        if(del_id != planets[i]->getID()) {
            p[j] = this->planets[i];
            j++;
        }
    }
    this->planets = p;
    delete[] planets;
    this->curr_planets--;
    return true;
}

void Star::orbit() {
    int curr_planets = this->getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        this->planets[i]->orbit();
    }
}

void Star::printStarInfo() {
    cout<<"\tThe star has "<<this->getCurrentNumPlanets()<<" planets."<<endl;
    cout<<"\tPlanets:"<<endl;
    for(int i=0; i<this->getCurrentNumPlanets(); i++) {
        Planet *planet = this->planets[i];
        cout<<"\t\tPlanet "<<planet->getID()<<" is "<<planet->getDistance()<<" million miles away at position "<<planet->getPos()<<" around the star."<<endl;
    }
}

int Star::getCurrentNumPlanets() {
    return this->curr_planets;
}

Starlist::Starlist() {
    this->curr_planets = 0;
}

Starlist::~Starlist() {
    star.~List();
}

long Starlist::addPlanet() {
    Planet *new_planet = new Planet(rand() % 3000);
    star.insert(curr_planets, new_planet);
    curr_planets++;
    return new_planet->getID();
}

bool Starlist::removePlanet(long id) {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        if(id == star.read(i)->getID()) {
            return star.remove(i);
        }
    }
    return false;
}

Planet * Starlist::getPlanet(long id) {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        if(id==star.read(i)->getID()) {
            return star.read(i);
        }
    }
    return NULL;
}

void Starlist::orbit() {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        star.read(i)->orbit();
    }
}

void Starlist::printStarInfo() {
    int curr_planets = getCurrentNumPlanets();
    cout<<"\tThe star has "<<curr_planets<<" planets."<<endl;
    cout<<"\tPlanets:"<<endl;
    for(int i=0; i<curr_planets; i++) {
        Planet *planet = star.read(i);
        cout<<"\t\tPlanet "<<planet->getID()<<" is "<<planet->getDistance()<<" million miles away at position "<<planet->getPos()<<" around the star."<<endl;
    }
}

unsigned int Starlist::getCurrentNumPlanets() {
    return star.size();
}

Starvector::Starvector() {
    curr_planets = 0;
}

Starvector::~Starvector() {
    star.~Vector();
}

long Starvector::addPlanet() {
    Planet *new_planet = new Planet(rand() % 3000);
    star.insert(curr_planets, new_planet);
    curr_planets+=1;
    return new_planet->getID();
}

bool Starvector::removePlanet(long id) {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        if(star.read(i)!=NULL) {
            if(id == star.read(i)->getID()){
                return star.remove(i);
            }
        }
    }
    return false;
}

Planet * Starvector::getPlanet(long id) {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        if(star.read(i)!=NULL) {
            if(id == star.read(i)->getID()) return star.read(i);
        }
    }
    return NULL;
}

void Starvector::orbit() {
    int curr_planets = getCurrentNumPlanets();
    for(int i=0; i<curr_planets; i++) {
        star.read(i)->orbit();
    }
}

void Starvector::printStarInfo() {
    int curr_planets = getCurrentNumPlanets();
    cout<<"\tThe star has "<<curr_planets<<" planets."<<endl;
    cout<<"\tPlanets:"<<endl;
    for(int i=0; i<curr_planets; i++) {
        Planet *planet = star.read(i);
        cout<<"\t\tPlanet "<<planet->getID()<<" is "<<planet->getDistance()<<" million miles away at position "<<planet->getPos()<<" around the star."<<endl;
    }
}

unsigned int Starvector::getCurrentNumPlanets() {
    return star.size();
}
