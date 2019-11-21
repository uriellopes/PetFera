#include "../includes/avenativa.h"
#include <iostream>

AveNativa::AveNativa(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, double k, double l, string m, string n, string o) {
    tipo = 2;
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
    uf_origem = m;
    autorizacao = n;
    autoriazacao_ibama = o;
}

AveNativa::~AveNativa() {}

void AveNativa::print(std::ostream &o) {
	o << 8 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << tamanho_do_bico_cm << ";" << envergadura_das_asas << ";"
	<< uf_origem << ";" << autorizacao << ";" << autoriazacao_ibama;
}