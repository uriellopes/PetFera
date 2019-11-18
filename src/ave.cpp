#include<iostream>
#include"ave.h"

using namespace std;

Ave::Ave(string classe, int id):Animal(classe,id){
	cout << "TAMANHO DO BICO: ";
	cin >> tamanho_bico;
	cout << "ENVERGADURA: ";
	cin >> envergadura;
}

Ave::~Ave(){}

int Ave::getTamanho_bico(){
	return this->tamanho_bico;
}

void Ave::setTamanho_bico(int tamanho_bico){
	this->tamanho_bico = tamanho_bico;
}

int Ave::getEnvergadura(){
	return this->envergadura;
}

void Ave::setEnvergadura(int envergadura){
	this->envergadura = envergadura;
}