#include "../includes/avenativa.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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

void AveNativa::atualizarDados() {
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
	cout << "Tamanho do bico: ";
	cin >> tamanho_do_bico_cm;
	cout << "Envergadura das asas: ";
	cin >> envergadura_das_asas;
	cout << "UF da origem: ";
	cin.ignore();
	getline(cin, uf_origem);
	cout << "Autorizacao: ";
	getline(cin, autorizacao);
	cout << "Autorizacao do Ibama: ";
	getline(cin, autoriazacao_ibama);
}

void AveNativa::mostrarDados() {
	cout << "Ave Silvestre Nativa" << endl;
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
	cout << "Tamanho do bico: " << tamanho_do_bico_cm << "cm" << endl;
	cout << "Envergadura das asas: " << envergadura_das_asas << "cm" << endl;
	cout << "UF da origem: " << uf_origem << endl;
	cout << "Autorizacao: " << autorizacao << endl;
	cout << "Autorizacao do Ibama: " << autoriazacao_ibama << endl << endl;
}