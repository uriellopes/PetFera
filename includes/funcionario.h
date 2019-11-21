#ifndef Funcionario_H
#define Funcionario_H

#include <string>
using std::string;

class Funcionario {
protected:
	int id;
	string nome;
	string cpf;
	int idade;
	string tipo_sanguineo;
	char fator_rh;
	string especialidade;
public:
	Funcionario();
	~Funcionario();
	friend std::ostream& operator<< (std::ostream &o, Funcionario &f);
	virtual void print(std::ostream &o) = 0;
	int getId();
	virtual void atualizarDados() = 0;
};

#endif