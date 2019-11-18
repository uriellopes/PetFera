#ifndef ANIMAL_H
#define ANIMAL_H

#include<iostream>
#include<fstream>
#include<cstdlib>
#include"tratador.h"
#include"veterinario.h"

using namespace std;

class Animal{
	protected:
		int id;
		string classe;
		string nome;
		string cientifico;
		char sexo;
		float tamanho;
		string dieta;
		Veterinario veterinario;
		int aux_veterinario;
		int aux_tratador; 
		Tratador tratador;
		string batismo;
	public:
		Animal(string classe, int id);
		~Animal();
		int getId();
		void setId(int id);
		string getClasse();
		void setClasse(string classe);
		string getNome();
		void setNome(string nome);
		string getCientifico();
		void setCientifico(string cientifico);
		char getSexo();
		void setSexo(char sexo);
		float getTamanho();
		void setTamanho(float tamanho);
		string getDieta();
		void setDieta(string dieta);
		Veterinario getVeterinario();
		void setVeterinario(Veterinario veterinario);
		Tratador getTratador();
		void setTratador(Tratador tratador);
		string getBatismo();
		void setBatismo(string batismo);		

};


		

#endif
