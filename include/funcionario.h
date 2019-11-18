#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

class Funcionario{
	protected:
		int id;
		string nome;
		string cpf;
		string tipo_sanguineo;
		char fatorRH;
		string especialidade;
	public:
		Funcionario();
		Funcionario(int id);
		int getId();
		void setId(int id);
		string getNome();
		void setNome(string nome);
		string getCpf();
		void setCpf(string cpf);
		string getTipo_sanguineo();
		void setTipo_sanguineo(string tipo_sanguineo);
		char getFatorRH();
		void setFatorRH(char fatorRH);
		string getEspecialidade();
		void setEspecialidade(string Especialidade);

};



#endif
