#include "Planet.h"
#include <iostream>
using namespace std;
#include "Vector.h"

Vector::Vector() {
	this->planets = NULL;
	this->size = 0;
}

Vector::~Vector() {
	for(int i=0; i<int(size); i++) {
		delete planets[i];
		planets[i] = NULL;
	}
	delete planets;
}

void Vector::insert(int index, Planet * planet) {
	int temp_size = size;
	if(index<temp_size) {
		Planet ** p1 = new Planet*[temp_size+1];
		for(int i=0; i<temp_size; i++) {
	        p1[i] = planets[i];
	        planets[i] = NULL;
	    }
	    for(int i=p1_size; i>index; i--) {
			p1[i] = p1[i-1];
		}
		delete[] planets;
		p1[index] = planet;
		size++;
		planets = p1;
	} else {
		Planet ** p1 = new Planet*[index+1];
		for(int i=0; i<temp_size; i++) {
	        p1[i] = planets[i];
	        planets[i] = NULL;
	    }
	    delete[] planets;
		p1[index] = planet;
		size=index+1;
		planets = p1;
	}
}

bool Vector::remove(int delindex) {
	if(delindex<int(size)) {
		Planet ** p1 = new Planet*[size-1];
    	int index = 0;
    	for(int i=0; i<int(size); i++) {
    		if(delindex != i) {
        		p1[index] = planets[i];
        		planets[i] = NULL;
        		index++;
        	} else {
        		if(planets[i] != NULL){
        			delete planets[i];	
        		} 
        		planets[i] = NULL;
        	}
    	}
    	delete[] planets;
    	planets = p1;
    	size--;
    	return true;
    }
	else return false;
}

Planet * Vector::read(int index) {
	if(planets[index]!=NULL){
		return planets[index];
	} 
	return NULL;
}

long int Vector::unsigned(){
    return this->size;
}