#include "Planet.h"
#include <stdio.h>
#include <cstdlib>


using namespace std;


Planet::Planet(int distance){
  this->id = (long int)this;
   this->distance = distance;
   this->pos = rand() % 360;
   char arrayNum[3] = {'r', 'h', 'g' };
   this->type = arrayNum[rand() % 3];
}

int Planet::orbit(){
   if (this->pos < 359){
       this->pos += 1;
   }else{
       this->pos = 0 ;
   }
   return this->pos;
}
