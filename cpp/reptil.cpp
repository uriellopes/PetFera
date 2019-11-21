#include "../includes/reptil.h"
#include <iostream>

Reptil::Reptil(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, bool k, string l) {
	tipo = 3;
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
    venenoso = k;
    tipo_veneno = l;
}

Reptil::Reptil() {}

Reptil::~Reptil() {}

void Reptil::print(std::ostream &o) {
	o << 3 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << venenoso << ";" << tipo_veneno;
}