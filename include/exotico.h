#ifndef EXOTICO_H
#define EXOTICO_H

#include<iostream>
#include"animalSilvestre.h"

using namespace std;

class Exotico : public AnimalSilvestre{
	protected:
		string pais_origem;
	public:
		string getPais_origem();
		void setPais_origem(string pais_origem);
};


#endif
