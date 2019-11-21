#ifndef AveNativa_H
#define AveNativa_H

#include "ave.h"
#include "animalnativo.h"

class AveNativa : public Ave, public AnimalNativo {
public:
    AveNativa(int, string, string, string, char, double, string, int, int, string, double, double, string, string, string);
    ~AveNativa();
    void print(std::ostream &o);
};

#endif