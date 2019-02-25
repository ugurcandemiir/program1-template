
#include "Planet.h"
#include "Vector.h"

Vector::Vector(){
	Planet ** planets = NULL;
	this->size = 0;
}

unsigned Vector::size(){
	return this->size;	
}
	
void Vector::insert(int index, Planet *p){			
	if(this->size >= index)	
		Planet ** planets = new Planet*[this->size+1];
		Planet *temp = new Planet(index+1);
		planets[this->index] = temp; 
	else{
		this->size = index+1;
		Planet **planets = new Planet*[this->size];			
	}	
}

Planet* Vector::read(int index){
	if(size < index){
		return NULL;
	}
	else{
		Planet *temp = planets[index];
		return temp;
	}
}

bool Vector::remove(int index){
	Planet **p1 = new Planet*[this->size-1];
    int j = 0;
    bool flag = false;
    for (int i = 0; i < this->size; i++){
      if ( (i+1) == index){
        delete planets[i];
        planets[i] = NULL;
        flag = true;
      }else{
        p1[j] = planets[i];
        j++;
      }
    }
    if(flag){
      this->size--;
    }
    delete[] planets;
    planets = NULL;
    planets = p1;
    p1 = NULL;
    return flag;
}


	
	
	
		
	
