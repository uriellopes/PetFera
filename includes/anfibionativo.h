#ifndef AnfibioNativo_H
#define AnfibioNativo_H

#include "anfibio.h"
#include "animalnativo.h"

class AnfibioNativo : public Anfibio, public AnimalNativo {
public:
	AnfibioNativo(int, string, string, string, char, double, string, int, int, string, int, string, string, string, string);
	~AnfibioNativo();
};

#endif