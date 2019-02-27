#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Planet.h"

class Node {
    public:
      

        Planet *planet;
        Node *next;
        Node *prev;
        Node() {
            planet = NULL;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            delete planet;
            next = NULL;
            prev = NULL;
            planet = NULL;
        }
};

class List {
    private:
        Node *head, *tail;
        unsigned size_of_list;
    public:
        List();
        ~List();
        void insert(int index, Planet *p);
        Planet* read(int index);
        bool remove(int index);
        void display();
        unsigned int size() {
          return this->size_of_list;
        }
};
#endif
