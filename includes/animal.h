#ifndef Animal_H
#define Animal_H

#include <string>
using std::string;

class Animal {
protected:
	int tipo;
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
	friend std::ostream& operator<< (std::ostream &o, Animal &a);
	virtual void print(std::ostream &o) = 0;
	int getId();
	virtual void atualizarDados() = 0;
	virtual void mostrarDados() = 0;
	void mostrarAnimais(int f);
	int getIdTratador();
	int getIdVeterinario();
};

#endif