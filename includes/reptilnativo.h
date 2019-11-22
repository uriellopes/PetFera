#ifndef ReptilNativo_H
#define ReptilNativo_H

#include "reptil.h"
#include "animalnativo.h"

class ReptilNativo : public Reptil, public AnimalNativo {
public:
    ReptilNativo(int, string, string, string, char, double, string, int, int, string, bool, string, string, string, string);
    ~ReptilNativo();
    void print(std::ostream &o);
    void atualizarDados();
};

#endif