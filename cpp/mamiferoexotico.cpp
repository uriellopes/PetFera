#include "../includes/mamiferoexotico.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

MamiferoExotico::MamiferoExotico(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, string k, string l, string m) {
	tipo = 0;
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

void MamiferoExotico::print(std::ostream &o) {
	o << 5 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << cor_do_pelo << ";" << pais_origem << ";" << autoriazacao_ibama;
}

void MamiferoExotico::atualizarDados() {
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
	cout << "Cor do pelo: ";
	getline(cin, cor_do_pelo);
	cout << "Pais de origem: ";
	getline(cin, pais_origem);
	cout << "Autorizacao do Ibama: ";
	getline(cin, autoriazacao_ibama);
}

void MamiferoExotico::mostrarDados() {
	cout << "Mamifero Silvestre Exotico" << endl;
	cout << "ID: " << id << endl;
	cout << "Classe: " << classe << endl;
	cout << "Nome: " << nome << endl;
	cout << "Nome Cientifico: " << nome_cientifico << endl;
	cout << "Sexo: " << sexo << endl;
	cout << "Tamanho: " << tamanho << "m" << endl;
	cout << "Dieta: " << dieta << endl;
	cout << "ID do tratador: " << tratador << endl;
	cout << "ID do veterinario: " << veterinario << endl;
	cout << "Nome de batismo: " << batismo << endl;
	cout << "Cor do pelo: " << cor_do_pelo << endl;
	cout << "Pais de origem: " << pais_origem << endl;
	cout << "Autorizacao do Ibama: " << autoriazacao_ibama << endl << endl;
}