#include "../includes/mamiferonativo.h"

MamiferoNativo::MamiferoNativo(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, string k, string l, string m, string n) {
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
	uf_origem = l;
	autorizacao = m;
	autoriazacao_ibama = n;
}

MamiferoNativo::~MamiferoNativo() {}