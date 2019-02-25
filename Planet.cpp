#include "Planet.h"
#include <stdio.h>
#include <cstdlib>

Planet::Planet(int distance){
  this->id = long(this);
   this->distance = distance;
   this->pos = rand() % 360;
   char arrayNum[3] = {'r', 'h', 'g' };
   arrayNum[rand() % 3];
}
int Planet::orbit(){
   if (this->pos < 359){
       this->pos += 1;
   }else{
       this->pos = 0 ;
   }
   return this->pos;
}

long int Planet::getID(){
   return this->id;
}
int Planet::getDistance(){
   return this->distance;
}
int Planet::getPos(){
   return this->pos;
}
char Planet::getType(){
   return type;
}

