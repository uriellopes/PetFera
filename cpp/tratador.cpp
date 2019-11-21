#include "../includes/tratador.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Tratador::Tratador(int a, string b, string c, int d, string e, char f, string g, int h) {
    funcao = 0;
	id = a;
	nome = b;
	cpf = c;
	idade = d;
	tipo_sanguineo = e;
	fator_rh = f;
	especialidade = g;
	nivel_seguranca = h;
}

Tratador::~Tratador() {}

void Tratador::print(std::ostream &o) {
	o << 0 << ";" << id << ";" << nome << ";" << cpf << ";" 
	<< idade << ";" << tipo_sanguineo << ";" << fator_rh << ";" 
	<< especialidade << ";" << nivel_seguranca;
}

void Tratador::atualizarDados() {
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "CPF: ";
    cin.ignore();
    getline(cin, cpf);
    cout << "Idade: ";
    cin >> idade;
    cout << "Tipo Sanguineo (A, B, AB ou O): ";
    cin.ignore();
    getline(cin, tipo_sanguineo);
    cout << "Fator RH ( + ou -): ";
    cin >> fator_rh;
    cout << "Especialidade: ";
    cin.ignore();
    getline(cin, especialidade);
    cout << "Nivel de segurança: ";
    cin >> nivel_seguranca;
}

void Tratador::mostrarDados() {
    cout << "Funcao: Tratador" << endl;
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Idade: " << idade << endl;
    cout << "Tipo Sanguineo: " << tipo_sanguineo << fator_rh << endl;
    cout << "Especialidade: " << especialidade << endl;
    cout << "Nivel de seguranca: " << nivel_seguranca << endl << endl;
}