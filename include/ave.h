#ifndef AVE_H
#define AVE_H

#include<iostream>
#include"animal.h"

using namespace std;

class Ave : public Animal{
	protected:
		int tamanho_bico;
		int envergadura;
	public:
		Ave(string classe, int id);
		~Ave();
		int getTamanho_bico();
		void setTamanho_bico(int tamanho_bico);
		int getEnvergadura();
		void setEnvergadura(int envergadura);

};



#endif
