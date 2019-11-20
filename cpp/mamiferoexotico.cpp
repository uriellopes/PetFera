#include "../includes/mamiferoexotico.h"

MamiferoExotico::MamiferoExotico(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, string k, string l, string m) {
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
	pais_origem = l;
	autoriazacao_ibama = m;
}

MamiferoExotico::~MamiferoExotico() {}