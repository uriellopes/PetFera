#include<iostream>
#include"reptil.h"

using namespace std;

Reptil::Reptil(string classe, int id):Animal(classe,id){
	cout << "(1) É VENENOSO (0) NÃO-VENENOSOS: ";
	cin >> venenoso;
	if(venenoso){	
		cout << "TIPO DO VENENO: ";
		cin >> tipo_veneno;
	}
}	

bool Reptil::getVenenoso(){
	return this->venenoso;
}

void Reptil::setVenenoso(bool venenoso){
	this->venenoso = venenoso;
}

string Reptil::getTipo_veneno(){
	return this->tipo_veneno;
}

void Reptil::setTipo_veneno(string tipo_veneno){
	this->tipo_veneno = tipo_veneno;
}