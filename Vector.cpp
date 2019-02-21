//
#include "Planet.h"
#include "Vector.h"

Vector::Vector(){
	Planet ** p = NULL;
	this->size = 0;
}

unsigned Vector::size(){
	return this->size;	
}
	

void Vector::insert(int index, Planet *p){			
	if(p.size() < index)	
		Planet ** p = new Planet*[size+1];
		Planet *temp = new Planet(index+1);
		p[this->index] = temp; 
	else{
		Planet **p = new Planet[size++];			
	}	
}

Planet* Vector::read(int index){
	if(size < index){
		return NULL;
	}
	else{
		Planet *temp = this->p[index];
		return temp;
	}
}

bool Vector::remove(){
	bool flag = TRUE;
	for(int i=0; i<this->size; i++){
		if(i == index){
			delete p[i];
			p[i] = NULL;
			this->size--;
		}
	}
	if(flag){ return flag;}
	return flag;
}


	
	
	
		
	
