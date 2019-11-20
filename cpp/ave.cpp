#include "../includes/ave.h"

Ave::Ave(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, double k, double l) {
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