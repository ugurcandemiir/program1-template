
#ifndef PLANET_H
#define PLANET_H
class Planet{
private:
    int id;
    int pos;
    int distance;
    char type;
public:
    Planet();
    Planet(int distance);
    int orbit();
    long int getID();
    int getDistance();
    int getPos();
    char getchar();
};
#endif
