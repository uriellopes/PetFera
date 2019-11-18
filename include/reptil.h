#ifndef REPTIL_H
#define REPTIL_H

#include<iostream>
#include"animal.h"

using namespace std;

class Reptil : public Animal{
	protected:
		bool venenoso;
		string tipo_veneno;
	public:
		Reptil(string classe, int id);
		bool getVenenoso();
		void setVenenoso(bool venenoso);
		string getTipo_veneno();
		void setTipo_veneno(string tipo_veneno);
};


#endif
