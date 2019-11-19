#ifndef Funcionario_H
#define Funcionario_H

#include <string>
using std::string;

class Funcionario {
protected:
	int id;
	string nome;
	string cpf;
	short idade;
	char sangue[2];
	char rh;
	string especialidade;
};

#endif