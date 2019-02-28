#include "Planet.h"
#include <iostream>
using namespace std;
#include "Vector.h"

Vector::Vector(){
	this->planets = NULL;
	this->current_size = 0;
}

Vector::~Vector(){
	for(int i=0; i<int(current_size); i++){
		delete planets[i];
		planets[i] = NULL;
	}
	delete[] planets;
}

void Vector::insert(int index, Planet * planet){
	int temp_size = current_size;
	if(index<temp_size){
		Planet ** p1 = new Planet*[temp_size+1]();
		for(int i=0; i<temp_size; i++){
	        p1[i] = planets[i];
	        planets[i] = NULL;
	    }
	    for(int i=temp_size; i>index; i--) { // temp_size
			p1[i] = p1[i-1];
		}
		delete[] planets;
		p1[index] = planet;
		current_size+=1;
		planets = p1;
	} else {
		Planet ** p1 = new Planet*[index+1]();
		for(int i=0; i<temp_size; i++) {
	        p1[i] = planets[i];
	        planets[i] = NULL;
	    }
	    delete[] planets;
		p1[index] = planet;
		current_size=index+1;
		planets = p1;
	}
}


bool Vector::remove(int delindex) {
	if(delindex<int(current_size)) {
		Planet ** p1 = new Planet*[current_size-1]();
    	int index = 0;
    	for(int i=0; i<int(current_size); i++) {
    		if(delindex == i) {
			if(planets[i] != NULL){
				delete planets[i];
			}
        	} else {
        		p1[index] = planets[i];
        		index++;
        	}
		planets[i] = NULL;
        }
    	delete[] planets;
    	planets = p1;
    	current_size-=1;
    	return true;
    }
	else return false;
}

Planet * Vector::read(int index) {
	if(index > int(current_size)){
		return NULL;
	}
	if(planets[index]!=NULL){
		return planets[index];
	}
	return NULL;
}
