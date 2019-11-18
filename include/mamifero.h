#ifndef MAMIFERO_H
#define MAMIFERO_H

#include<iostream>
#include"animal.h"

using namespace std;

class Mamifero : public Animal {
	protected:
		string cor_pelo;
	public:
		Mamifero(string classe, int id);
		string getCor_pelo();
		void setCor_pelo(string cor_pelo);
};



#endif
