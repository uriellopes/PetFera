#ifndef MamiferoNativo_H
#define MamiferoNativo_H

#include "mamifero.h"
#include "animalnativo.h"

class MamiferoNativo : public Mamifero, public AnimalNativo {
public:
    MamiferoNativo(int, string, string, string, char, double, string, int, int, string, string, string, string, string);
    ~MamiferoNativo();
    void print(std::ostream &o);
    void atualizarDados();
    void mostrarDados();
};

#endif