#ifndef Ave_H
#define Ave_H

#include "animal.h"

class Ave : public Animal {
protected:
    double tamanho_do_bico_cm;
    double envergadura_das_asas;
public:
    Ave(int, string, string, string, char, double, string, int, int, string, double, double);
    Ave();
    ~Ave();
    void print(std::ostream &o);
};

#endif