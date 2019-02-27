
#include "Star.h"
#include <stdio.h>
#include <cstdlib>

Star::Star(){
    this->current_planets =  0;
    this->next_id = 0;
    planets  = NULL;
}

Star::~Star(){}

long Star::addPlanet(){
    Planet**p = new Planet*[current_planets+1];
    for (int i = 0 ; i < current_planets ; i++){
      p[i] = planets[i] ;
      planets[i]= NULL;
    }
    Planet* new_p = new Planet(rand() % 3000,current_planets+1);
    p [this->current_planets] = new_p ;
    this->current_planets++;
    planets= p;
    p = NULL;
    return new_p->getID();

}

bool Star::removePlanet(int id){
  bool flag = false;
  Planet**p1 = new Planet*[current_planets-1];
  int b =0;
  for (int i = 0 ; i < current_planets ; i++){
    if (planets[i]->getID() == id){
      delete planets[i];
      planets[i] = NULL;
      flag = true;
    }else{
        p1[b] = planets[i];
        b++;
    }
  }
  if (flag){this->current_planets--;}
  delete [] planets;
  planets = p1;
  p1 = NULL;
  return flag;

}

Planet* Star::getPlanet(int id){
  if (id <= current_planets){
    return planets[id-1];
  }else{
    return NULL;
  }
}

void Star:: orbit(){
  for (int i = 0 ; i< current_planets; i++){
    planets[i]->orbit();
  }
}
void Star::printStarInfo(){
  printf("The star currently has %d planets.\n" , current_planets );
  printf("Planets: \n");
  for(int i = 0; i < current_planets; i++){
    printf("\tPlanet %d is %d million miles away at position %d around the star.\n",i, planets[i]->getDistance(), planets[i]->getPos());
  }
}
