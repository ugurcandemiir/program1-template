#ifndef VECTOR_H
#define VECTOR_H
#include "Planet.h"
class Vector {      
    private:
        Planet ** planets;
        unsigned size;
    public:
        Vector();
        ~Vector();
        void insert(int index, Planet *p);
        Planet* read(int index);
        bool remove(int index);
};
#endif