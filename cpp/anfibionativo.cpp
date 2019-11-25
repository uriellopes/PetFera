#include "../includes/anfibionativo.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

AnfibioNativo::AnfibioNativo(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, int k, string l, string m, string n, string o) {
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
	uf_origem = m;
	autorizacao = n;
	autoriazacao_ibama = o;
}

AnfibioNativo::~AnfibioNativo() {}

void AnfibioNativo::print(std::ostream &o) {
	o << 6 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << total_de_mudas << ";" << ultima_muda << ";"
	<< uf_origem << ";" << autorizacao << ";" << autoriazacao_ibama;
}

void AnfibioNativo::atualizarDados() {
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
	cout << "Total de mudas: ";
	cin >> total_de_mudas;
	cout << "Ultima muda: ";
	cin.ignore();
	getline(cin, ultima_muda);
	cout << "UF da origem: ";
	getline(cin, uf_origem);
	cout << "Autorizacao: ";
	getline(cin, autorizacao);
	cout << "Autorizacao do Ibama: ";
	getline(cin, autoriazacao_ibama);
}

void AnfibioNativo::mostrarDados() {
	cout << "Anfibio Silvestre Nativo" << endl;
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
	cout << "Total de mudas: " << total_de_mudas << endl;
	cout << "Ultima muda: " << ultima_muda << endl;
	cout << "UF da origem: " << uf_origem << endl;
	cout << "Autorizacao: " << autorizacao << endl;
	cout << "Autorizacao do Ibama: " << autoriazacao_ibama << endl << endl;
}