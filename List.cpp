#include <iostream>
using namespace std;
#include "List.h"

List::List() {
	head = NULL;
	tail = NULL;
	size = 0;
}

List::~List() {
	for(int i=0; i<int(size); i++){
		this->remove(0);
	} 
}

void List::insert(int index, Planet * p){
	Node *temp = new Node();
	temp->p = p;
	if(head == NULL){
		head = temp;
		tail = temp;
		size++;
	} else if(index == 0){
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else{
		if( index<int(size) ){
			int len = 0;
			Node *traversal = head;
			while( len!=index && traversal->next != NULL){
				traversal = traversal->next;
				len++;
			}
			Node *prev_node = traversal->prev;
			prev_node->next = temp;
			temp->next = traversal;
			temp->prev = prev_node;
			traversal->prev = temp;
		}else{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		size++;
	}
}

bool List::remove(int index){
	if( index>=int(size) ){
		return false;
	}
	if( size==1 ){
		delete head;
		delete tail;
		head = NULL;
		tail = NULL;
		size--;
		return true;
	}
	if( index==0 ){
		Node *t = head;
		head = head->next;
		head->prev = NULL;
		t->next=NULL;
		t->prev=NULL;
		delete t;
		size--;
		return true;
	}
	if(index==int(size)-1){
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
		size--;
		return true;
	}
	Node *traversal = head;
	int len = 0;
	while(len!=index){
		traversal = traversal->next;
		len++;
	}
	Node *next_node = traversal->next;
	Node *prev_node = traversal->prev;
	prev_node->next = next_node;
	next_node->prev = prev_node;
	size--;
	delete traversal;
	traversal=NULL;
	return true;
}

Planet* List::read(int index){
	if( index>int(size) ){ 
		return NULL;
	}
	int len = 0;
	Node *traversal = head;
	while(traversal->next != NULL && len!=index){
		traversal = traversal->next;
		len++;
	}
	return traversal->planet;
}