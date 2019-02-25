
#include "List.h"

List::List(){
	this->head = NULL;
	this->current = NULL;
	this->size = 0;
}

List::~List(){

}

void List::insert(int index,Planet *p){
	Node *temp = new Node;
	temp->data = *p;
	temp->next = NULL;
	temp->prev = NULL;

	Node *t1 = new Node;
	t1->next = NULL;
	t1->prev = NULL;

	if((this->size) >= index){
		if(head == NULL){
			temp->next = head;
			head->prev = temp;
			head = temp;
			temp = NULL;
			size++;
		}
		else{
			int len = 0;
			while(current->next != NULL && len == (index)){
				current = current->next;
				len++;
			}
			t1 = current->prev;
			temp->next = current;
			t1->next = temp;
			temp->prev = t1;
			this->size++;
			}
	}
	else{
		while(current->next != NULL){
			current = current->next;
		}
		temp->prev = current;
		current->next = temp;
		this->size++;
	}
	delete temp;
	delete t1;
}

Planet * List::read(int index){
	if(size() >= index){
		int len = 0;
			while(current->next != NULL && len == (index)){
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
    bool flag = false;
    current = head;
    Node *temp = new Node;
    temp->prev = NULL:
   	temp->next = NULL;

   	Node *t1 = new Node;
	t1->next = NULL;
	t1->prev = NULL;

    if(index == 0){
    	head = head->next;
    	current->next = NULL;
    	head->prev = NULL;
    	flag = true;
    }
    if(index > 0 && index < size){
    	for (int i = 1; i <= this->size; i++){
    		current = current->next;
    		if (i == index){
        		temp = current;
        		current = current->next;
        		t1 = temp->prev;
        		current->prev = NULL:
        		t1->next  = NULL;
        		temp->next = NULL;
        		temp->prev = NULL;
        		current->prev = t1;
        		t1->next = current;
        		flag = true;
        	}
        }
    }else{
    	while(current->next != NULL){
    		current = current->next;
    	}
    	temp = current;
    	temp->prev = NULL;
    	current->prev->next = NULL;  	
    }
    if(flag){
      this->size--;
    }
    delete temp;
    return flag;
}

unsigned List::size(){
	return this->size;
}