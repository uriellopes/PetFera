#include "../includes/veterinario.h"

#include <iostream>
using std::cout;
using std::cin;

Veterinario::Veterinario(int a, string b, string c, int d, string e, char f, string g, string h) {
	id = a;
	nome = b;
	cpf = c;
	idade = d;
	tipo_sanguineo = e;
	fator_rh = f;
	especialidade = g;
	crmv = h;
}

Veterinario::~Veterinario() {}

void Veterinario::print(std::ostream &o) {
	o << 1 << ";" << id << ";" << nome << ";" << cpf << ";" 
	<< idade << ";" << tipo_sanguineo << ";" << fator_rh << ";" 
	<< especialidade << ";" << crmv;
}

void Veterinario::atualizarDados() {
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
    cout << "CRMV: ";
    getline(cin, crmv);
}