#include "../includes/anfibio.h"
#include <iostream>

Anfibio::Anfibio(int a, string b, string c,	string d, char e, double f, string g, int h, int i, string j, int k, string l) {
	tipo = 1;
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
	total_de_mudas = k;
	ultima_muda = l;
}

Anfibio::Anfibio() {}

Anfibio::~Anfibio() {}

void Anfibio::print(std::ostream &o) {
	o << 1 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << total_de_mudas << ";" << ultima_muda;
}