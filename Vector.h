#ifndef VECTOR_H
#define VECTOR_H
#include "Vector.h"
class Vector{
private:
    int index;
    int size;
public:
    Vector **vectors;
    Vector();
    ~Vector();
    void insert(int index, Planet * p);
    Planet* read(int index)
    bool remove(int index)
    unsigned size()
    //you may add any additional methodas you may need.
};
#endif
