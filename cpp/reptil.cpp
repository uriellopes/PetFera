#include "../includes/reptil.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Reptil::Reptil(int a, string b, string c, string d, char e, double f, string g, int h, int i, string j, bool k, string l) {
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
}

Reptil::Reptil() {}

Reptil::~Reptil() {}

void Reptil::print(std::ostream &o) {
	o << 3 << ";" << id << ";" << classe << ";" << nome << ";" 
	<< nome_cientifico << ";" << sexo << ";" << tamanho << ";" 
	<< dieta << ";" << tratador << ";" << veterinario << ";" 
	<< batismo << ";" << venenoso << ";" << tipo_veneno;
}

void Reptil::atualizarDados() {
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
}

void Reptil::mostrarDados() {
	cout << "Reptil Domestico" << endl;
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
	cout << "Venenoso: ";
	if( venenoso ) {
		cout << "Sim" << endl;
	} else {
		cout << "Nao" << endl;
	}
	cout << "Tipo do veneno: " << tipo_veneno << endl << endl;
}