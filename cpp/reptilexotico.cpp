#include "../includes/reptilexotico.h"

ReptilExotico::ReptilExotico(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, bool k, string l, string m, string n) {
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
    venenoso = k;
    tipo_veneno = l;
    pais_origem = m;
    autoriazacao_ibama = n;
}

ReptilExotico::~ReptilExotico() {}