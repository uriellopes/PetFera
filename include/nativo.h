#ifndef NATIVO_H
#define NATIVO_H

#include<iostream>
#include"animalSilvestre.h"

using namespace std;

class Nativo : public AnimalSilvestre{
	protected:
		string uf_origem;
		string autorizacao;
	public:
		string getUf_origem();
		void setUf_origem(string uf_origem);
		string getAutorizacao();
		void setAutorizacao(string autorizacao);
};



#endif
