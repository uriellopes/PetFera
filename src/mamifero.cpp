#include<iostream>
#include"mamifero.h"

using namespace std;

Mamifero::Mamifero(string classe, int id):Animal(classe, id){
	cout << "COR DO PELO: ";
	cin >> cor_pelo;
}

string Mamifero::getCor_pelo(){
	return this->cor_pelo;
}

void Mamifero::setCor_pelo(string cor_pelo){
	this->cor_pelo = cor_pelo;
}	