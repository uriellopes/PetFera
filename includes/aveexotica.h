#ifndef AveExotica_H
#define AveExotica_H

#include "ave.h"
#include "animalexotico.h"

class AveExotica : public Ave, public AnimalExotico {
public:
    AveExotica(int, string, string, string, char, double, string, int, int, string, double, double, string, string);
    ~AveExotica();
    void print(std::ostream &o);
    void atualizarDados();
};

#endif