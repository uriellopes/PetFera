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

std::ostream& operator<< (std::ostream &o, Veterinario const v) {
    o << 1 << ";" << v.id << ";" << v.nome << ";" << v.cpf << ";" 
	<< v.idade << ";" << v.tipo_sanguineio << ";" << v.fator_rh << ";" 
	<< v.especialidade << ";" << v.crmv;
	return o;
}