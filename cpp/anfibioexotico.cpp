#include "../includes/anfibioexotico.h"
#include <iostream>

AnfibioExotico::AnfibioExotico(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, int k, string l, string m, string n) {
	tipo = 1;
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
	pais_origem = m;
	autoriazacao_ibama = n;
}

AnfibioExotico::~AnfibioExotico() {}

void AnfibioExotico::print(std::ostream &o) {
	o << 7 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << total_de_mudas << ";" << ultima_muda << ";"
	<< pais_origem <<";" << autoriazacao_ibama;
}