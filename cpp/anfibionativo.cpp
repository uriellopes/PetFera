#include "../includes/anfibionativo.h"

AnfibioNativo::AnfibioNativo(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, int k, string l, string m, string n, string o) {
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
	total_de_mudas = k;
	ultima_muda = l;
	uf_origem = m;
	autorizacao = n;
	autoriazacao_ibama = o;
}

AnfibioNativo::~AnfibioNativo() {}