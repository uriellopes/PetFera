#ifndef Reptil_H
#define Reptil_H

#include "animal.h"

class Reptil : public Animal {
protected:
    bool venenoso;
    string tipo_veneno;
public:
    Reptil(int, string, string, string, char, double, string, int, int, string, bool, string);
    Reptil();
    ~Reptil();
};

#endif