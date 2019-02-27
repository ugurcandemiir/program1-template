#ifndef PLANET_H
#define PLANET_H

class Planet{
    private:
        int pos;
        int distance;
        char type;
        long int id;
    public:
        Planet(int distance);
        int orbit();
        long int getID(){return this->id;}
        int getDistance(){return this->distance;}
        int getPos(){return this->pos;}
        char getType(){return this->type;}
};
#endif
