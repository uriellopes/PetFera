#ifndef ANFIBIO_H
#define ANFIBIO_H

#include<iostream>
#include"animal.h"

using namespace std;

class Anfibio : public Animal {
	protected:
		string ultima_muda;
		int total_mudas;
	public:
		Anfibio(string classe, int id);
		~Anfibio();
		string getUltima_muda();
		void setUltima_muda(string ultima_muda);
		int getTotal_mudas();
		void setTotal_mudas(int total_mudas);

};



#endif
