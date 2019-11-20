#ifndef Mamifero_H
#define Mamifero_H

#include "animal.h"

class Mamifero : public Animal {
protected:
    string cor_do_pelo;
public:
    Mamifero(int, string, string, string, char, double, string, int, int, string, string);
    Mamifero();
    ~Mamifero();
};

#endif