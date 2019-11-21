#include "../includes/mamifero.h"
#include <iostream>

Mamifero::Mamifero(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, string k) {
	tipo = 0;
    id = a;
	classe = b;
	nome = c;
	nome_cientifico = d;
	sexo = e;
	tamanho = f;
	dieta = g;
	tratador = h;
	veterinario = i;
	batismo = j;
	cor_do_pelo = k;
}

Mamifero::Mamifero() {}

Mamifero::~Mamifero() {}

void Mamifero::print(std::ostream &o) {
	o << 0 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << cor_do_pelo;
}