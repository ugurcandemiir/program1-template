// 
#include "List.h"

List::List(){
	this->head = NULL;
	this->current = NULL;
	this->previous = NULL;
	this->size = 0;
}

List::~List(){

}

void List::insert(int index,Planet *p){
	Node *temp = new Node;
	temp->data = *p;
	temp->next = NULL;
	temp->prev = NULL;
	if((l.size()+1) >= index){
		if(head == NULL){
			temp->next = head;
			head->prev = temp;
			head = temp;
			temp = NULL;
			size++;
		}
		else{
			int len = 0;
			while(current->next != NULL && len == (index-1)){
				current = current->next;
				len++;
			}
			previous = current;
			current = current->next;
			previous->next = temp;
			temp->prev = current;
			temp->next = current;
			current->prev = temp;
			size++;
			}
	}
	else{
		while(current->next != NULL){
			current = current->next;
		}
		temp->prev = current;
		current->next = temp;
		previous = current;
		current = temp;
		temp = NULL;
		size++;
	}
}

Planet * List::read(int index){
	if(size() >= index){
		int len = 0;
			while(current->next != NULL && len == (index-1)){
				current = current->next;
				len++;
			}
			Planet * p1 = *(current->data);
			return p1;
	}
	else{
		return NULL;
	}
}

bool List::remove(int index){//not done
	Planet **p1 = new Planet*[planets.size()-1];
    int j = 0;
    bool flag = false;
    for (int i = 0; i < planets.size(); i++){
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

unsigned List::size(){
	return this->size;
}