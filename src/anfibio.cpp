#include<iostream>
#include"anfibio.h"

using namespace std;

Anfibio::Anfibio(string classe, int id):Animal(classe,id){
	cout << "TOTAL DE MUDAS: ";
	cin >> total_mudas;
	cout << "ULTIMA MUDA: ";
	cin >> ultima_muda;
}

Anfibio::~Anfibio(){}

string Anfibio::getUltima_muda(){
	return this->ultima_muda;
}

void Anfibio::setUltima_muda(string ultima_muda){
	this->ultima_muda = ultima_muda;
}

int Anfibio::getTotal_mudas(){
	return this->total_mudas;
}

void Anfibio::setTotal_mudas(int total_mudas){
	this->total_mudas = total_mudas;
}