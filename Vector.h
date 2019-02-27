#ifndef VECTOR_H
#define VECTOR_H
#include "Planet.h"
class Vector {
    private:
        Planet ** planetsm;
        unsigned current_size;
    public:
        Vector();
        ~Vector();
        void insert(int index, Planet *p);
        Planet* read(int index);
        bool remove(int index);
        unsigned size(){
          return this->current_size;
        }
};
#endif
