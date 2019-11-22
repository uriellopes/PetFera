#include "../includes/reptilexotico.h"
#include <iostream>
using std::cout;
using std::cin;

ReptilExotico::ReptilExotico(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, bool k, string l, string m, string n) {
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
    pais_origem = m;
    autoriazacao_ibama = n;
}

ReptilExotico::~ReptilExotico() {}

void ReptilExotico::print(std::ostream &o) {
	o << 11 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << venenoso << ";" << tipo_veneno << ";"
	<< pais_origem << ";" << autoriazacao_ibama;
}

void ReptilExotico::atualizarDados() {
	cout << "Nome: ";
	cin.ignore();
	getline(cin, nome);
	cout << "Nome Cientifico: ";
	getline(cin, nome_cientifico);
	cout << "Sexo: ";
	cin >> sexo;
	cout << "Tamanho: ";
	cin >> tamanho;
	cout << "Dieta: ";
	cin.ignore();
	getline(cin, dieta);
	cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
	cin >> tratador;
	cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
	cin >> veterinario;
	cout << "Nome de batismo: ";
	cin.ignore();
	getline(cin, batismo);
	cout << "Venenoso ([1] - Sim / [0] - Nao): ";
	cin >> venenoso;
	cout << "Tipo do veneno: ";
	cin.ignore();
	getline(cin, tipo_veneno);
	cout << "Pais de origem: ";
	getline(cin, pais_origem);
	cout << "Autorizacao do Ibama: ";
	getline(cin, autoriazacao_ibama);
}