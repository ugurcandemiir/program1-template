
#ifndef PLANET_H
#define PLANET_H
class Planet{
private:
    int id;
    int pos;
    int distance;
    char type;
public:
    Planet(){this->id=-1;};
    Planet(int distance, int id);
    int orbit();
    long getID();
    int getDistance();
    int getPos();
    char getType();
    void setID(int);
    void setDistance(int);
    void setPos(int);
    void setType(int);


    //you may add any additional methods you may need.
};
#endif
