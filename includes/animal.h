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
	string batismo;
	int tratador;
	int veterinario;
public:
	Animal(int c_id);
	~Animal();
	int getId();
	friend std::ostream& operator<< (std::ostream &o, Animal const a);
};

Animal::Animal(int c_id) {
	id = c_id;
}

Animal::~Animal() {}

int Animal::getId() {
	return id;
}

std::ostream& operator<< (std::ostream &o, Animal const a) {
    o << a.id << ";TESTANDO PARA VER SE DEU CERTO";
    return o;
}