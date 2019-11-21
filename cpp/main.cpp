#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;

#include <sstream>
using std::stringstream;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include "../includes/tratador.h"
#include "../includes/veterinario.h"

//Verifica o tipo de SO para definir o tipo da variavel para limpar o terminal
#ifdef _WIN32
#define LIMPAR "CLS"
#else
#define LIMPAR "clear"
#endif


//Função para pressionar enter para continuar
void clear() {
    system(LIMPAR);
}

//Função para checar se o input é um int
bool checarDigito(string &input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            return false;
            break;
        }
    }
    return true;
}

//Função para ler os dados dos arquivos
void lerDados(vector<shared_ptr<Funcionario>> &f) {
    
    ifstream file_animais("funcionarios.csv");

    vector<string> values;
    string line, value;

    while(!file_animais.eof()) {
        getline(file_animais, line);
        if ( !line.empty() ) {
            stringstream temp(line);
            values.clear();
            while(getline(temp, value, ';')) {
                values.push_back(value);
            }
            switch (stoi(values[0])) {
            case 0:
                f.push_back(shared_ptr<Tratador>(new Tratador(stoi(values[1]), values[2], values[3], stoi(values[4]), values[5], *values[6].c_str(), values[7], stoi(values[8]))));
                break;
            case 1:
                f.push_back(shared_ptr<Veterinario>(new Veterinario(stoi(values[1]), values[2], values[3], stoi(values[4]), values[5], *values[6].c_str(), values[7], values[8])));
                break;
            }
        }
    }

    file_animais.close();
}

//Função para salvar os dados nos arquivos
void salvarDados(vector<shared_ptr<Funcionario>> &f) {

    ofstream file_funcionarios("funcionarios.csv");

    for (unsigned i = 0; i < f.size(); i++) {
        file_funcionarios << *f[i] << endl;
    }

    file_funcionarios.close();
}

void menuFuncionarios(vector<shared_ptr<Funcionario>> &f) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "#############################################################" << endl;
        cout << "###                      FUNCIONARIOS                     ###" << endl;
        cout << "#############################################################" << endl;
        cout << endl << "Escolha uma das seguintes opcoes: " << endl << endl;
        cout << "[1] - Adicionar novo funcionario" << endl;
        cout << "[2] - Remover funcionario" << endl;
        cout << "[3] - Alterar dados de funcionario" << endl;
        cout << endl;
        cout << "[0] - Sair" << endl << endl;

        if (error) {
            error = false;
            cout << "**Digite uma opcao valida!**" << endl;
        }
        cout << "Opcao: ";
        cin >> input;

        if (checarDigito(input)) {
            escolha = stoi(input, nullptr);

            if (escolha >= 0 && escolha <= 3) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    //
                    break;
                case 2:
                    //
                    break;
                case 3:
                    //
                    break;
                }
            } else {
                error = true;
            }
        } else {
            error = true;
        }
    } while (!sair);
}

//Função que mostra o menu principal
void menuPrincipal(vector<shared_ptr<Funcionario>> &f) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "############################################################" << endl;
        cout << "###                      BEM VINDO!!                     ###" << endl;
        cout << "############################################################" << endl;
        cout << endl << "Escolha uma das seguintes opcoes: " << endl << endl;
        cout << "[1] - Animais" << endl;
        cout << "[2] - Funcionarios" << endl;
        cout << endl;
        cout << "[0] - Sair" << endl << endl;

        if (error) {
            error = false;
            cout << "**Digite uma opcao valida!**" << endl;
        }
        cout << "Opcao: ";
        cin >> input;

        if (checarDigito(input)) {
            escolha = stoi(input, nullptr);

            if (escolha >= 0 && escolha <= 2) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    //
                    break;
                case 2:
                    menuFuncionarios(f);
                    break;
                }
            } else {
                error = true;
            }
        } else {
            error = true;
        }
    } while (!sair);
}

int main() {

    vector<shared_ptr<Funcionario>> funcionarios;

	lerDados(funcionarios);

    menuPrincipal(funcionarios);

	salvarDados(funcionarios);

	return 0;
}