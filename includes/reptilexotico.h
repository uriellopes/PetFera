#ifndef ReptilExotico_H
#define ReptilExotico_H

#include "reptil.h"
#include "animalexotico.h"

class ReptilExotico : public Reptil, public AnimalExotico {
public:
    ReptilExotico(int, string, string, string, char, double, string, int, int, string, bool, string, string, string);
    ~ReptilExotico();
    void print(std::ostream &o);
};

#endif