#include <iostream>
#include "../includes/animal.h"

Animal::Animal(int c_id, 
	string c_classe, 
	string c_nome, 
	string c_nome_cientifico, 
	char c_sexo, 
	double c_tamanho, 
	string c_dieta, 
	int c_veterinario, 
	int c_tratador, 
	string c_batismo) 
{
	id = c_id;
	classe = c_classe;
	nome = c_nome;
	nome_cientifico = c_nome_cientifico;
	sexo = c_sexo;
	tamanho = c_tamanho;
	dieta = c_dieta;
	veterinario = c_veterinario;
	tratador = c_tratador;
	batismo = c_batismo;
}

Animal::~Animal() {}

std::ostream& operator<< (std::ostream &o, Animal const a) {
    o << a.id << ";" 
    << a.classe << ";" 
    << a.nome << ";" 
    << a.nome_cientifico << ";" 
    << a.sexo << ";" 
    << a.tamanho << ";" 
    << a.dieta << ";" 
    << a.veterinario << ";" 
    << a.tratador << ";" 
    << a.batismo;
    return o;
}