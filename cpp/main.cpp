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

//Função pressionar para continuar
void pressToCont() {
    cout << "Pressione Enter para continuar...";
    cin.ignore();
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

//Função para cadastrar um tratador
void novoTratador(vector<shared_ptr<Funcionario>> &f) {
    int id, idade, nivel_seguranca;
    char fator_rh;
    string nome, cpf, tipo_sanguineo, especialidade;
    bool existe;

    cout << "Digite as informaçoes do novo tratador" << endl;
    cout << "ID: ";
    cin >> id;

    for (unsigned i = 0; i < f.size(); i++) {
        if( f[i]->getId() == id ) {
            existe = true;
            break;
        }
    }

    if ( !existe ) {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "CPF: ";
        cin.ignore();
        getline(cin, cpf);
        cout << "Idade: ";
        cin >> idade;
        cout << "Tipo Sanguineo (A, B, AB ou O): ";
        cin.ignore();
        getline(cin, tipo_sanguineo);
        cout << "Fator RH ( + ou -): ";
        cin >> fator_rh;
        cout << "Especialidade: ";
        cin.ignore();
        getline(cin, especialidade);
        cout << "Nivel de segurança: ";
        cin >> nivel_seguranca;

        f.push_back(shared_ptr<Tratador>(new Tratador(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, nivel_seguranca)));

        cout << endl << "Novo tratador cadastrado com sucesso!" << endl << endl;
    } else {
        cout << endl << "Já existe um funcionario cadastrado com esse ID" << endl << endl;
    }
    cin.ignore();
}

//Função para cadastrar um veterinario
void novoVeterinario(vector<shared_ptr<Funcionario>> &f) {
    int id, idade;
    char fator_rh;
    string nome, cpf, tipo_sanguineo, especialidade, crmv;
    bool existe = false;

    cout << "Digite as informaçoes do novo tratador" << endl;
    cout << "ID: ";
    cin >> id;

    for (unsigned i = 0; i < f.size(); i++) {
        if( f[i]->getId() == id ) {
            existe = true;
            break;
        }
    }

    if ( !existe ) {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "CPF: ";
        cin.ignore();
        getline(cin, cpf);
        cout << "Idade: ";
        cin >> idade;
        cout << "Tipo Sanguineo (A, B, AB ou O): ";
        cin.ignore();
        getline(cin, tipo_sanguineo);
        cout << "Fator RH ( + ou -): ";
        cin >> fator_rh;
        cout << "Especialidade: ";
        cin.ignore();
        getline(cin, especialidade);
        cout << "CRMV: ";
        cin >> crmv;

        f.push_back(shared_ptr<Veterinario>(new Veterinario(id, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade, crmv)));

        cout << endl << "Novo veterinario cadastrado com sucesso!" << endl << endl;
    } else {
        cout << endl << "Já existe um funcionario cadastrado com esse ID" << endl << endl;
    }
    cin.ignore();
}

//Função para remover um funcionario
void removerFuncionario(vector<shared_ptr<Funcionario>> &f) {
    int id;
    bool existe = false;
    cout << "Digite o ID do funcionario: ";
    cin >> id;
    for (unsigned i = 0; i < f.size(); i++) {
        if( f[i]->getId() == id ) {
            f.erase(f.begin() + i);
            existe = true;
            break;
        }
    }
    if( existe ) {
        cout << "Funcionario removido com sucesso!" << endl;
    } else {
        cout << "Não existe funcionario com esse id cadastrado!" << endl;
    }
}

//Função para alterar dados de um funcionario
void alterarFuncionario(vector<shared_ptr<Funcionario>> &f) {
    int id;        
    bool existe = false;
    cout << "Digite o ID do funcionario: ";
    cin >> id;
    for (unsigned i = 0; i < f.size(); i++) {
        if( f[i]->getId() == id ) {
            f[i]->atualizarDados();
            existe = true;
            break;
        }
    }
    if( existe ) {
        cout << "Informacoes do funcionario atualizadas com sucesso!" << endl;
    } else {
        cout << "Não existe funcionario com esse id cadastrado!" << endl;
    }
}

//Menu de funcionarios
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
        cout << "[1] - Adicionar novo tratador" << endl;
        cout << "[2] - Adicionar novo veterinario" << endl;
        cout << "[3] - Remover funcionario" << endl;
        cout << "[4] - Alterar dados de funcionario" << endl;
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

            if (escolha >= 0 && escolha <= 4) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    clear();
                    novoTratador(f);
                    pressToCont();
                    break;
                case 2:
                    clear();
                    novoVeterinario(f);
                    pressToCont();
                    break;
                case 3:
                    clear();
                    removerFuncionario(f);
                    pressToCont();
                    break;
                case 4:
                    clear();
                    alterarFuncionario(f);
                    pressToCont();
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