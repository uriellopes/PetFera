#ifndef AnimalNativo_H
#define AnimalNativo_H

#include "animalsilvestre.h"

class AnimalNativo : public AnimalSilvestre {
protected:
	string uf_origem;
	string autorizacao;
public:
	AnimalNativo();
	~AnimalNativo();	
};

#endif