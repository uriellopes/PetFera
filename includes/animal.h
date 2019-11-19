#include <string>
using std::string;

class Animal {
private:
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
	Animal(int c_id, 
		string c_classe, 
		string c_nome, 
		string c_nome_cientifico, 
		char c_sexo, 
		double c_tamanho, 
		string c_dieta, 
		int c_veterinario, 
		int c_tratador, 
		string c_batismo);
	~Animal();
	friend std::ostream& operator<< (std::ostream &o, Animal const a);
};