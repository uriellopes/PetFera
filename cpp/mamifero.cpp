#include "../includes/mamifero.h"

Mamifero::Mamifero(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, string k) {
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