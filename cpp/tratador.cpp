#include "../includes/tratador.h"

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