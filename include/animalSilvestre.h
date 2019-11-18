#ifndef ANIMAL_SILVESTRE_H
#define ANIMAL_SILVESTRE_H

#include<iostream>

using namespace std;

class AnimalSilvestre {
	protected:
		string ibama;
	public:
		string getIbama();
		void setIbama(string ibama);
};


#endif
