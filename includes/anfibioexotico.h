#ifndef AnfibioExotico_H
#define AnfibioExotico_H

#include "anfibio.h"
#include "animalexotico.h"

class AnfibioExotico : public Anfibio, public AnimalExotico {
public:
	AnfibioExotico(int, string, string, string, char, double, string, int, int, string, int, string, string, string);
	~AnfibioExotico();
	void print(std::ostream &o);
};

#endif