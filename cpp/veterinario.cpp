#include "../includes/veterinario.h"

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