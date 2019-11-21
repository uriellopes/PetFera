#include "../includes/ave.h"
#include <iostream>

Ave::Ave(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, double k, double l) {
	tipo = 2;
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
    tamanho_do_bico_cm = k;
    envergadura_das_asas = l;
}

Ave::Ave() {}

Ave::~Ave() {}

void Ave::print(std::ostream &o) {
	o << 2 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << tamanho_do_bico_cm << ";" << envergadura_das_asas;
}