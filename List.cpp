#include <iostream>
using namespace std;
#include "List.h"

List::List() {
	head = NULL;
	tail = NULL;
	size_of_list = 0;
}

List::~List() {
	while(head != tail){
		head = head->next;
		delete head->prev;
		head->prev = NULL;
	}
	delete tail;
	head = NULL;
	tail = NULL;
}


void List::insert(int index, Planet * p){
	Node *temp = new Node();
	temp->planet = p;
	if(head == NULL){
		head = temp;
		tail = temp;
		size_of_list++;
	} else if(index == 0){
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else{
		if( index<int(size_of_list) ){
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
		size_of_list++;
	}
}

bool List::remove(int index){
	if( index>=int(size_of_list) ){
		return false;
	}
	if( size_of_list==1 ){
		delete head;
		delete tail;
		head = NULL;
		tail = NULL;
		size_of_list--;
		return true;
	}
	if( index==0 ){
		Node *t = head;
		head = head->next;
		head->prev = NULL;
		t->next=NULL;
		t->prev=NULL;
		delete t;
		size_of_list--;
		return true;
	}
	if(index==int(size_of_list)-1){
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
		size_of_list--;
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
	size_of_list--;
	delete traversal;
	traversal=NULL;
	return true;
}

Planet* List::read(int index){
	if( index>int(size_of_list) ){
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
