#ifndef AnimalExotico_H
#define AnimalExotico_H

#include "animalsilvestre.h"

class AnimalExotico : public AnimalSilvestre {
protected:
	string pais_origem;
public:
	AnimalExotico();
	~AnimalExotico();	
};

#endif