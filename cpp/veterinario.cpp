#include "../includes/veterinario.h"
#include <iostream>

Veterinario::Veterinario(int a, string b, string c, int d, string e, char f, string g, string h) {
	id = a;
	nome = b;
	cpf = c;
	idade = d;
	tipo_sanguineio = e;
	fator_rh = f;
	especialidade = g;
	crmv = h;
}

Veterinario::~Veterinario() {}

void Veterinario::print(std::ostream &o) {
	o << 1 << ";" << id << ";" << nome << ";" << cpf << ";" 
	<< idade << ";" << tipo_sanguineio << ";" << fator_rh << ";" 
	<< especialidade << ";" << crmv;
}