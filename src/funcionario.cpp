#include<iostream>
#include"funcionario.h"

using namespace std;

Funcionario::Funcionario(){

}

Funcionario::Funcionario(int id){
	//system("clear");
	this->id = id;
	cout << "NOME: ";
	cin >> nome;
	cout << "CPF: ";
	cin >> cpf;
	cout << "TIPO SANGUINEO: ";
	cin >> tipo_sanguineo;
	cout << "FATOR RH: ";
	cin >> fatorRH;
	cout << "ESPECIALIDADE: ";
	cin >> especialidade;
	ofstream arquivo;
		arquivo.open("funcionarios.csv", ios::app);
		if (arquivo.is_open() && arquivo.good()){
			arquivo << id << ";" << nome << ";" << cpf << ";" << tipo_sanguineo << ";" << fatorRH << ";" << especialidade << endl;
			arquivo.close();
		}
		else {
			cout << "Não foi possivel salvar as informações" << endl;
		}
}

int Funcionario::getId(){
	return id;
}

void Funcionario::setId(int id){
	this->id=id;
}

string Funcionario::getNome(){
	return nome;
}

void Funcionario::setNome(string nome){
	this->nome = nome;
}

string Funcionario::getCpf(){
	return cpf;
}

void Funcionario::setCpf(string cpf){
	this->cpf=cpf;
}

string Funcionario::getTipo_sanguineo(){
	return tipo_sanguineo;
}

void Funcionario::setTipo_sanguineo(string tipo_sanguineo){
	this->tipo_sanguineo = tipo_sanguineo;
}

char Funcionario::getFatorRH(){
	return fatorRH;
}

void Funcionario::setFatorRH(char fatorRH){
	this->fatorRH = fatorRH;
}

string Funcionario::getEspecialidade(){
	return especialidade;
}

void Funcionario::setEspecialidade(string especialidade){
	this->especialidade = especialidade;
}
