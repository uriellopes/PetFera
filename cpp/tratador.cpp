#include "../includes/tratador.h"

#include <iostream>

Tratador::Tratador(int a, string b, string c, int d, string e, char f, string g, int h) {
	id = a;
	nome = b;
	cpf = c;
	idade = d;
	tipo_sanguineio = e;
	fator_rh = f;
	especialidade = g;
	nivel_seguranca = h;
}

Tratador::~Tratador() {}

std::ostream& operator<< (std::ostream &o, Tratador const t) {
    o << 0 << ";" << t.id << ";" << t.nome << ";" << t.cpf << ";" 
	<< t.idade << ";" << t.tipo_sanguineio << ";" << t.fator_rh << ";" 
	<< t.especialidade << ";" << t.nivel_seguranca;
	return o;
}