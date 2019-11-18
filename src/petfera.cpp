#include<iostream>
#include"anfibio.h"
#include"animalSilvestre.h"
#include"ave.h"
#include"exotico.h"
#include"mamifero.h"
#include"reptil.h"
#include"veterinario.h"
#include"animal.h"
#include"aveExotica.h"
#include"aveNativa.h"
#include"funcionario.h"
#include"nativo.h"
#include"tratador.h"
#include"funcoes_gerais.h"
#include<vector>

using namespace std;

void menu_inicial();
/* VARIÁVEIS GLOBAIS */
vector<Animal> animais;
vector<Funcionario> funcionarios;
/*------------------*/
int main(int argc, char *argv[]){
	menu_inicial();

	return 0;
}


