#ifndef Animal_H
#define Animal_H

#include <string>
using std::string;

class Animal {
protected:
	int id;
	string classe;
	string nome;
	string nome_cientifico;
	char sexo;
	double tamanho;
	string dieta;
	int tratador;
	int veterinario;
	string batismo;
public:
	Animal();
	~Animal();
};

#endif