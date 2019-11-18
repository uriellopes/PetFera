#include<iostream>
#include"funcoes_gerais.h"

using namespace std;

string getNome_Funcionario(int id, string nome_arquivo){
	ifstream arquivo;
	arquivo.open(nome_arquivo);
	string linha;
	string nome="";
	int aux_id;
	while(!arquivo.eof()){
		getline(arquivo, linha);
		aux_id = (int(linha[0]))-48;
		if(id == aux_id){
		int i = 2;
			while(linha[i]!=';'){
				nome = nome + linha[i];
				i++;
			}
			arquivo.close();
			return nome;
		}
	}
	arquivo.close();
	return "NOT FOUND";
}

void limpa_tela(){
	int i=0;
	cout << "Entre com um valor diferente de zero para limpar a tela: ";
	cin >> i;
	if(i){
		system("clear");
	} 
}

void consulta(string entrada, string nome_arquivo){
	ifstream arquivo;
	arquivo.open(nome_arquivo);
	string linha;
	cout << "Resultado da Busca: "<< endl;
	while(!arquivo.eof()){
		getline(arquivo,linha);
		if(linha.find(entrada)!=string::npos){
			cout << linha << endl;
		}
	}
	arquivo.close();
	limpa_tela();
}

void exportar(string entrada1, string entrada2, string entrada3, string nome_arquivo_ent, string nome_arquivo_saida){
	ifstream arquivo;
	ofstream arquivo_saida;
	arquivo.open(nome_arquivo_ent);
	arquivo_saida.open(nome_arquivo_saida);
	string linha;
	while(!arquivo.eof()){
		getline(arquivo,linha);
		if((linha.find(entrada1)!=string::npos) && (linha.find(entrada2)!=string::npos) && (linha.find(entrada3)!=string::npos)){
			arquivo_saida << linha << endl;
		}
	}
	arquivo_saida.close();
	arquivo.close();
}

void remove_cadastro(int remove_id, string nome_arquivo){
	ifstream arquivo_in;
	ofstream arquivo_out;
	string linha;
	int aux_id;

	arquivo_in.open(nome_arquivo);
	nome_arquivo = nome_arquivo + "2";
	arquivo_out.open(nome_arquivo);
	while(!arquivo_in.eof()){
		getline(arquivo_in, linha);
		aux_id = (int)(linha[0])-48;
		if(aux_id != remove_id && !arquivo_in.eof()){
			arquivo_out << linha;
			arquivo_out << endl;
		}
	}

	if(!nome_arquivo.compare("animais.csv2")){
		system("rm animais.csv");
		system("mv animais.csv2 animais.csv");
	}

	if(!nome_arquivo.compare("funcionarios.csv2")){
		system("rm funcionarios.csv");
		system("mv funcionarios.csv2 funcionarios.csv");
	}	
	
	arquivo_in.close();
	arquivo_out.close();
	limpa_tela();
}

int id_value(string nome_arquivo){
	fstream arquivo;
	arquivo.open(nome_arquivo);
	int aux=-5;
	string linha;
	if (arquivo.is_open() && arquivo.good()){
		while(!arquivo.eof()){			
			arquivo >> aux;
		}
		arquivo.close();

		ofstream arquivo_aux;
		arquivo_aux.open(nome_arquivo);
		aux++;
		arquivo_aux << aux;
		return aux;
	}
	else {
		cout << "Nao foi possivel carregar a informacao de ID" << endl;
		return -1; 
	}
}

void mostra_arquivo(string nome_arquivo){
	system("clear");
	ifstream arquivo;
	arquivo.open(nome_arquivo);
	string aux;

	cout << "Imprimindo arquivo " << nome_arquivo << endl << endl;
	if (arquivo.is_open() && arquivo.good()){
		while(!arquivo.eof()){
			arquivo >> aux;
			if(!arquivo.eof()){
				cout << aux << endl;
			}
		}

		arquivo.close();
	}
	else {
		cout << "Não foi possivel carregar as informações" << endl;
	}
}

void menu_inicial(){
	char opcao = '1';
	while(opcao!='9'){
		cout << endl << endl << "BEM VINDO! " << endl;
		cout << "--------------ANIMAL--------------" << endl;
		cout << "DIGITE 1 PARA CADASTRAR" << endl;
		cout << "DIGITE 2 REMOVER UM CADASTRO" << endl;
		cout << "DIGITE 3 PARA ALTERAR UM CADASTRO" << endl;
		cout << "DIGITE 4 PARA CONSULTA" << endl << endl;
		cout << "-----------FUNCIONARIO------------" << endl;
		cout << "DIGTE 5 PARA CONSULTAR ANIMAL SOB TRATOR DE UM VETERINARIO OU TRATADOR" << endl;
		cout << "DIGITE 6 PARA CADASTRAR FUNCIONARIO" << endl;
		cout << "DIGITE 7 PARA REMOVER FUNCIONARIO" << endl;  
		cout << "DIGITE 8 PARA ALTERAR FUNCIONARIO" << endl;
		cout << endl << "DIGITE 9 PARA SAIR" << endl;
		cin >> opcao;
		
		switch (opcao){
			case '1':{
				system("clear");
				int opcao_classe;	
				cout << "CLASSE: (1) MAMÍFERO (2) REPTIL (3)ANFÍBIO (4)AVE: ";
				cin >> opcao_classe;
				switch(opcao_classe){
					case 1: {
						Mamifero mamifero("Mammalia", id_value("id_animal.conf"));
						limpa_tela();
					}
					break;
					
					case 2: {
						Reptil reptil("Reptilia", id_value("id_animal.conf"));
						limpa_tela();
					}
					break;

					case 3: {
						Anfibio anfibio("Amphibia", id_value("id_animal.conf"));
						limpa_tela();
					}
					break;

					case 4: {
						Ave ave("Ave", id_value("id_animal.conf"));
						limpa_tela();
					}
					break;
					
					default:
						cout << "OPCAO INVALIDA!" << endl;
				}			

			}
			break;

			case '2':{
				system("clear");
				int remove_id;
				mostra_arquivo("animais.csv");
				cout << endl << "DIGITE O ID DO CADASTRO QUE DESEJA REMOVER: ";
				cin >> remove_id;
				remove_cadastro(remove_id, "animais.csv");
				limpa_tela();
			}
			break;

			case '3':{
				system("clear");
				int id_alteracao;
				mostra_arquivo("animais.csv");
				cout << endl << "ENTRE COM O ID DO CADASTRO QUE DESEJA ALTERAR: ";
				cin >> id_alteracao;
				remove_cadastro(id_alteracao, "animais.csv");
				int opcao_classe;	
				cout << "NOVA CLASSE: (1) MAMÍFERO (2) REPTIL (3)ANFÍBIO (4)AVE: ";
				cin >> opcao_classe;
				switch(opcao_classe){
					case 1: {
						Mamifero mamifero("Mammalia", id_alteracao);
						limpa_tela();
					}
					break;
					
					case 2: {
						Reptil reptil("Reptilia", id_alteracao);
						limpa_tela();
					}
					break;

					case 3: {
						Anfibio anfibio("Amphibia", id_alteracao);
						limpa_tela();
					}
					break;

					case 4: {
						Ave ave("Ave", id_alteracao);
						limpa_tela();
					}
					break;
					
					default:
						cout << "OPCAO INVALIDA!" << endl;
				}	
				
			}
			break;

			case '4':{
				system("clear");
				int opcao_busca;
				string entrada;
				cout << "DIGITE 1 PARA BUSCAR POR NOME. DIGITE 2 PARA BUSCAR POR CLASSE: ";
				cin >> opcao_busca;
				if(opcao_busca==1){
					cout << "DIGITE O NOME: ";
					cin >> entrada;
					consulta(entrada, "animais.csv");
				}
				else if(opcao_busca==2){
					cout << "BUSCA POR CLASSE: (1) MAMÍFERO (2) REPTIL (3)ANFÍBIO (4)AVE: ";
					cin >> opcao_busca;
					switch(opcao_busca){
					case 1: {
						consulta("Mammalia", "animais.csv");
					}
					break;
					
					case 2: {
						consulta("Reptilia", "animais.csv");
					}
					break;

					case 3: {
						consulta("Amphibia", "animais.csv");
					}
					break;

					case 4: {
						consulta("Ave", "animais.csv");
					}
					break;
					
					default:
						cout << "OPCAO INVALIDA!" << endl;
				}	
				}
			}		
			break;

			case '5':{
				system("clear");
				//IMPLEMENTAR
			}
			break;

			case '6':{
				system("clear");
				int opcao;
				system("clear");
				cout << "DIGITE: (1) PARA VETERINARIO (2) PARA TRATDOR: ";
				cin >> opcao;
				if(opcao==1){
					Veterinario veterinario(id_value("id_func.conf")); //**@brief Chama o construtor e passa o id
				}
				if(opcao==2){
					Tratador tratador(id_value("id_func.conf")); //Chama o construtor e passa o id
					
				}
			}
			break;

			case '7':{
				system("clear");
				int remove_id;
				mostra_arquivo("funcionarios.csv");
				cout << endl << "DIGITE O ID DO CADASTRO QUE DESEJA REMOVER: ";
				cin >> remove_id;
				remove_cadastro(remove_id, "funcionarios.csv");
				limpa_tela();
			}
			break;

			case '8':{
				system("clear");
				int id_alteracao;
				mostra_arquivo("funcionarios.csv");
				cout << endl << "ENTRE COM O ID DO CADASTRO QUE DESEJA ALTERAR: ";
				cin >> id_alteracao;
				remove_cadastro(id_alteracao, "funcionarios.csv");
				Funcionario funcionario(id_alteracao);
			}
			break;
		}
	}
}
