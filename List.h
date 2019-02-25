#ifndef LIST_H
#define LIST_H
#include "Planet.h"
 
class Node{
private:
	Planet data;
	Node *next;
	Node *prev;
}

class List
{
private:
	Node *head,*current;
	unsigned size;
public:
	List();
	~List();
	void insert(int index,Planet *planets);
	Planet *read(int index);
	bool remove(int index);
	unsigned size();
}
#endif