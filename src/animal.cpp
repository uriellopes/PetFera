#include<iostream>
#include"animal.h"
#include"funcoes_gerais.h"

using namespace std;

Animal::Animal(string classe, int id){
	system("clear");
	int id_veterinario, id_tratador;
	string nome_veterinario, nome_tratador;
	this->id = id;
	this->classe = classe;
	cout << "NOME: ";
	cin >> nome;
	cout << "NOME CIENTÍFICO: ";
	cin >> cientifico;
	cout << "SEXO [M/F]: ";
	cin >> sexo;
	cout << "TAMANHO: ";
	cin >> tamanho;
	cout << "DIETA: ";
	cin >> dieta;
	cout << "POSSUI VETERINARIO? [(1)/(0)]: ";
	cin >> aux_veterinario;
	if(aux_veterinario){
		mostra_arquivo("funcionarios.csv");
		cout << "Entre com o ID do Veterinario: ";
		cin >> id_veterinario;
		nome_veterinario = getNome_Funcionario(id_veterinario,"funcionarios.csv");
		cout << "NOME TRATADOR: " << nome_tratador << endl;
	}	
	else {
		nome_veterinario = " ";
	}
	cout << "POSSUI TRATADOR? [(1)/(0)]: ";
	cin >> aux_tratador;
	if(aux_tratador){
		mostra_arquivo("funcionarios.csv");
		cout << "Entre com o ID do Tratador: ";
		cin >> id_tratador;
		nome_tratador = getNome_Funcionario(id_tratador,"funcionarios.csv");
		cout << "NOME TRATADOR: " << nome_tratador << endl;
	}	
	else {
		nome_tratador = " ";
	}
	cout << "BATISMO: ";
	cin >> batismo;

	//**@brief Colocando informações no disco (arquivo);
	ofstream arquivo_animal;
	arquivo_animal.open("animais.csv", ios::app);
	if (arquivo_animal.is_open() && arquivo_animal.good()){
		arquivo_animal << id << ";" << classe << ";" << nome << ";" << cientifico << ";" << sexo << ";" << tamanho <<	";" << dieta << ";" << aux_veterinario << ";" << nome_veterinario << ";" << aux_tratador << ";" << nome_tratador << ";" << batismo <<";"<< endl;

		arquivo_animal.close();
	}
	else {
		cout << "Não foi possivel salvar as informações" << endl;
	}

}

Animal::~Animal(){}

int Animal::getId(){
	return this->id;
}

void Animal::setId(int id){
	this->id = id;
}

string Animal::getClasse(){
	return this->classe;
}

void Animal::setClasse(string classe){
	this->classe = classe;
}

string Animal::getNome(){
	return this->nome;
}

void Animal::setNome(string nome){
	this->nome = nome;
}

string Animal::getCientifico(){
	return this->cientifico;
}

void Animal::setCientifico(string cientifico){
	this->cientifico = cientifico;
}

char Animal::getSexo(){
	return this->sexo;
}

void Animal::setSexo(char sexo){
	this->sexo = sexo;
}

float Animal::getTamanho(){
	return this->tamanho;
}

void Animal::setTamanho(float tamanho){
	this->tamanho = tamanho;
}

string Animal::getDieta(){
	return this->dieta;
}

void Animal::setDieta(string dieta){
	this->dieta = dieta;
}

Veterinario Animal::getVeterinario(){
	return this->veterinario;
}

void Animal::setVeterinario(Veterinario veterinario){
	this->veterinario = veterinario;
}

Tratador Animal::getTratador(){
	return this->tratador;
}

void Animal::setTratador(Tratador tratador){
	this->tratador = tratador;
}

string Animal::getBatismo(){
	return this->batismo;
}

void Animal::setBatismo(string batismo){
	this->batismo = batismo;
}
