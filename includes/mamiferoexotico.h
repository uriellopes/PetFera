#ifndef MamiferoExotico_H
#define MamiferoExotico_H

#include "mamifero.h"
#include "animalexotico.h"

class MamiferoExotico : public Mamifero, public AnimalExotico {
public:
    MamiferoExotico(int, string, string, string, char, double, string, int, int, string, string, string, string);
    ~MamiferoExotico();
    void print(std::ostream &o);
    void atualizarDados();
    void mostrarDados();
};

#endif