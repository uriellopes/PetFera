#ifndef Tratador_H
#define Tratador_H

#include "funcionario.h"

class Tratador : public Funcionario {
private:
	int nivel_seguranca;
public:
	Tratador(int, string, string, int, string, char, string, int);
	~Tratador();
	friend std::ostream& operator<< (std::ostream &o, Tratador const t);
};

#endif