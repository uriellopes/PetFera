#include "../includes/reptilnativo.h"
#include <iostream>

ReptilNativo::ReptilNativo(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, bool k, string l, string m, string n, string o) {
    tipo = 3;
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
    uf_origem = m;
    autorizacao = n;
    autoriazacao_ibama = o;
}

ReptilNativo::~ReptilNativo() {}

void ReptilNativo::print(std::ostream &o) {
	o << 10 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << venenoso << ";" << tipo_veneno << ";"
	<< uf_origem << ";" << autorizacao << ";" << autoriazacao_ibama;
}