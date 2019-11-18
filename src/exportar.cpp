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
#include<string>
#include<list>

using namespace std;

void menu_inicial();
/* VARIÁVEIS GLOBAIS */
vector<Animal> animais;
vector<Funcionario> funcionarios;
/*------------------*/
int main(int argc, char *argv[]){
	std::list<string> argumentos;
	string varC = "";
	string varV = "";
	string varT = "";
	string varArquivo_saida = "";


	for (int i = 0; i < (argc - 1); ++i)
	{
		argumentos.push_back(argv[i + 1]);
	}

	if (!argumentos.empty() && argumentos.front() == "-c")
	{
		argumentos.pop_front();
		varC = argumentos.front();
		argumentos.pop_front();
	}

	if (!argumentos.empty() && argumentos.front() == "-v")
	{
		argumentos.pop_front();
		varV = argumentos.front();
		argumentos.pop_front();
	}

	if (!argumentos.empty() && argumentos.front() == "-t")
	{
		argumentos.pop_front();
		varT = argumentos.front();
		argumentos.pop_front();
	}

	varArquivo_saida = argumentos.front();

	exportar(varC, varV, varT, "animais.csv", varArquivo_saida);

	//menu_inicial();

	return 0;
}