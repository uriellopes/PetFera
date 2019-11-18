#include<iostream>
#include"nativo.h"

using namespace std;

string Nativo::getUf_origem(){
	return this->uf_origem;
}

void Nativo::setUf_origem(string uf_origem){
	this->uf_origem = uf_origem;
}

string Nativo::getAutorizacao(){
	return this->autorizacao;
}

void Nativo::setAutorizacao(string autorizacao){
	this->autorizacao = autorizacao;
}