#include "../includes/anfibioexotico.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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

void AnfibioExotico::atualizarDados() {
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
	cout << "Pais de origem: ";
	getline(cin, pais_origem);
	cout << "Autorizacao do Ibama: ";
	getline(cin, autoriazacao_ibama);
}

void AnfibioExotico::mostrarDados() {
	cout << "Anfibio Silvestre Exotico" << endl;
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
	cout << "Pais de origem: " << pais_origem << endl;
	cout << "Autorizacao do Ibama: " << autoriazacao_ibama << endl << endl;
}