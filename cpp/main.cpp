#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::find_if;

#include <memory>
using std::shared_ptr;

#include <sstream>
using std::stringstream;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include "../includes/anfibioexotico.h"
#include "../includes/mamiferoexotico.h"
#include "../includes/aveexotica.h"
#include "../includes/reptilexotico.h"
#include "../includes/anfibionativo.h"
#include "../includes/mamiferonativo.h"
#include "../includes/avenativa.h"
#include "../includes/reptilnativo.h"

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
void lerDados(vector<shared_ptr<Funcionario>> &f, vector<shared_ptr<Animal>> &a) {
    
    ifstream file_funcionarios("funcionarios.csv");

    vector<string> values;
    string line, value;

    while(!file_funcionarios.eof()) {
        getline(file_funcionarios, line);
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

    file_funcionarios.close();

    ifstream file_animais("animais.csv");

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
                a.push_back(shared_ptr<Mamifero>(new Mamifero(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], values[11])));
                break;
            case 1:
                a.push_back(shared_ptr<Anfibio>(new Anfibio(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), values[12])));
                break;
            case 2:
                a.push_back(shared_ptr<Ave>(new Ave(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), stoi(values[12]))));
                break;
            case 3:
                a.push_back(shared_ptr<Reptil>(new Reptil(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), values[12])));
                break;
            case 4:
                a.push_back(shared_ptr<MamiferoNativo>(new MamiferoNativo(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], values[11], values[12], values[13], values[14])));
                break;
            case 5:
                a.push_back(shared_ptr<MamiferoExotico>(new MamiferoExotico(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], values[11], values[12], values[13])));
                break;
            case 6:
                a.push_back(shared_ptr<AnfibioNativo>(new AnfibioNativo(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), values[12], values[13], values[14], values[15])));
                break;
            case 7:
                a.push_back(shared_ptr<AnfibioExotico>(new AnfibioExotico(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), values[12], values[13], values[14])));
                break;
            case 8:
                a.push_back(shared_ptr<AveNativa>(new AveNativa(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), stoi(values[12]), values[13], values[14], values[15])));
                break;
            case 9:
                a.push_back(shared_ptr<AveExotica>(new AveExotica(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), stoi(values[12]), values[13], values[14])));
                break;
            case 10:
                a.push_back(shared_ptr<ReptilNativo>(new ReptilNativo(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), values[12], values[13], values[14], values[15])));
                break;
            case 11:
                a.push_back(shared_ptr<ReptilExotico>(new ReptilExotico(stoi(values[1]), values[2], values[3], values[4], *values[5].c_str(), stod(values[6]), values[7], stoi(values[8]), stoi(values[9]), values[10], stoi(values[11]), values[12], values[13], values[14])));
                break;
            }
        }
    }

    file_animais.close();
}

//Função para salvar os dados nos arquivos
void salvarDados(vector<shared_ptr<Funcionario>> &f, vector<shared_ptr<Animal>> &a) {

    ofstream file_funcionarios("funcionarios.csv");

    for (unsigned i = 0; i < f.size(); i++) {
        file_funcionarios << *f[i] << endl;
    }

    file_funcionarios.close();

    ofstream file_animais("teste.csv");

    for (unsigned i = 0; i < a.size(); i++) {
        file_animais << *a[i] << endl;
    }

    file_animais.close();
}

//Função para cadastrar um mamifero domestico
void cadastrarMamiferoDomestico(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario;
	string nome, nome_cientifico, dieta, batismo, cor_do_pelo;
	char sexo;
	double tamanho;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Cor do pelo: ";
        getline(cin, cor_do_pelo);

        a.push_back(shared_ptr<Mamifero>(new Mamifero(id, "Mammalia", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, cor_do_pelo)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função para cadastrar um mamifero silvestre nativo
void cadastrarMamiferoNativo(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario;
	string nome, nome_cientifico, dieta, batismo, cor_do_pelo, uf_origem, autorizacao, autorizacao_ibama;
	char sexo;
	double tamanho;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Cor do pelo: ";
        getline(cin, cor_do_pelo);
        cout << "UF de origem: ";
        getline(cin, uf_origem);
        cout << "Autorizacao: ";
        getline(cin, autorizacao);
        cout << "Autorizacao do Ibama: ";
        getline(cin, autorizacao_ibama);

        a.push_back(shared_ptr<MamiferoNativo>(new MamiferoNativo(id, "Mammalia", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, cor_do_pelo, uf_origem, autorizacao, autorizacao_ibama)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função para cadastrar um mamifero silvestre exotico
void cadastrarMamiferoExotico(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario;
	string nome, nome_cientifico, dieta, batismo, cor_do_pelo, pais_origem, autorizacao_ibama;
	char sexo;
	double tamanho;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Cor do pelo: ";
        getline(cin, cor_do_pelo);
        cout << "Pais de origem: ";
        getline(cin, pais_origem);
        cout << "Autorizacao do Ibama: ";
        getline(cin, autorizacao_ibama);

        a.push_back(shared_ptr<MamiferoExotico>(new MamiferoExotico(id, "Mammalia", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, cor_do_pelo, pais_origem, autorizacao_ibama)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função com menu para escolher se o mamifero é domestico, nativo ou exotico
void cadastrarMamifero(vector<shared_ptr<Animal>> &a) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "########################################################" << endl;
        cout << "###                 NOVO MAMIFERO                    ###" << endl;
        cout << "########################################################" << endl;
        cout << endl << "Escolha o tipo do novo mamifero: " << endl << endl;
        cout << "[1] - Domestico" << endl;
        cout << "[2] - Nativo" << endl;
        cout << "[3] - Exotico" << endl;
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
                    clear();
                    cadastrarMamiferoDomestico(a);
                    pressToCont();
                    break;
                case 2:
                    clear();
                    cadastrarMamiferoNativo(a);
                    pressToCont();
                    break;
                case 3:
                    clear();
                    cadastrarMamiferoExotico(a);
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

//Função para cadastrar um anfibio domestico
void cadastrarAnfibioDomestico(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario, total_de_mudas;
    string nome, nome_cientifico, dieta, batismo, ultima_muda;
    char sexo;
    double tamanho;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Total de mudas: ";
        cin >> total_de_mudas;
        cout << "Ultima muda: ";
        cin.ignore();
        getline(cin, ultima_muda);

        a.push_back(shared_ptr<Anfibio>(new Anfibio(id, "Amphibia", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, total_de_mudas, ultima_muda)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função para cadastrar um anfibio nativo
void cadastrarAnfibioNativo(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario, total_de_mudas;
    string nome, nome_cientifico, dieta, batismo, ultima_muda, uf_origem, autorizacao, autorizacao_ibama;
    char sexo;
    double tamanho;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Total de mudas: ";
        cin >> total_de_mudas;
        cout << "Ultima muda: ";
        cin.ignore();
        getline(cin, ultima_muda);
        cout << "UF da origem: ";
        getline(cin, uf_origem);
        cout << "Autorizacao: ";
        getline(cin, autorizacao);
        cout << "Autorizacao do Ibama: ";
        getline(cin, autorizacao_ibama);

        a.push_back(shared_ptr<AnfibioNativo>(new AnfibioNativo(id, "Amphibia", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, total_de_mudas, ultima_muda, uf_origem, autorizacao, autorizacao_ibama)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função para cadastrar um anfibio exotico
void cadastrarAnfibioExotico(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario, total_de_mudas;
    string nome, nome_cientifico, dieta, batismo, ultima_muda, pais_origem, autorizacao_ibama;
    char sexo;
    double tamanho;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Total de mudas: ";
        cin >> total_de_mudas;
        cout << "Ultima muda: ";
        cin.ignore();
        getline(cin, ultima_muda);
        cout << "Pais de origem: ";
        getline(cin, pais_origem);
        cout << "Autorizacao do Ibama: ";
        getline(cin, autorizacao_ibama);

        a.push_back(shared_ptr<AnfibioExotico>(new AnfibioExotico(id, "Amphibia", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, total_de_mudas, ultima_muda, pais_origem, autorizacao_ibama)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função com menu para escolher se o anfibio é domestico, nativo ou exotico
void cadastrarAnfibio(vector<shared_ptr<Animal>> &a) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "########################################################" << endl;
        cout << "###                  NOVO ANFIBIO                    ###" << endl;
        cout << "########################################################" << endl;
        cout << endl << "Escolha o tipo do novo mamifero: " << endl << endl;
        cout << "[1] - Domestico" << endl;
        cout << "[2] - Nativo" << endl;
        cout << "[3] - Exotico" << endl;
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
                    clear();
                    cadastrarAnfibioDomestico(a);
                    pressToCont();
                    break;
                case 2:
                    clear();
                    cadastrarAnfibioNativo(a);
                    pressToCont();
                    break;
                case 3:
                    clear();
                    cadastrarAnfibioExotico(a);
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

//Função para cadastrar ave domestica
void cadastrarAveDomestica(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario;
    string nome, nome_cientifico, dieta, batismo;
    char sexo;
    double tamanho, tamanho_do_bico_cm, envergadura_das_asas;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Tamanho do bico: ";
        cin >> tamanho_do_bico_cm;
        cout << "Envergadura das asas: ";
        cin >> envergadura_das_asas;
        cin.ignore();

        a.push_back(shared_ptr<Ave>(new Ave(id, "Aves", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, tamanho_do_bico_cm, envergadura_das_asas)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função para cadastrar ave nativa
void cadastrarAveNativa(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario;
    string nome, nome_cientifico, dieta, batismo, uf_origem, autorizacao, autorizacao_ibama;
    char sexo;
    double tamanho, tamanho_do_bico_cm, envergadura_das_asas;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Tamanho do bico: ";
        cin >> tamanho_do_bico_cm;
        cout << "Envergadura das asas: ";
        cin >> envergadura_das_asas;
        cout << "UF da origem: ";
        cin.ignore();
        getline(cin, uf_origem);
        cout << "Autorizacao: ";
        getline(cin, autorizacao);
        cout << "Autorizacao do Ibama: ";
        getline(cin, autorizacao_ibama);

        a.push_back(shared_ptr<AveNativa>(new AveNativa(id, "Aves", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, tamanho_do_bico_cm, envergadura_das_asas, uf_origem, autorizacao, autorizacao_ibama)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função para cadastrar ave exotica
void cadastrarAveExotica(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario;
    string nome, nome_cientifico, dieta, batismo, pais_origem, autorizacao_ibama;
    char sexo;
    double tamanho, tamanho_do_bico_cm, envergadura_das_asas;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Tamanho do bico: ";
        cin >> tamanho_do_bico_cm;
        cout << "Envergadura das asas: ";
        cin >> envergadura_das_asas;
        cout << "Pais de origem: ";
        cin.ignore();
        getline(cin, pais_origem);
        cout << "Autorizacao do Ibama: ";
        getline(cin, autorizacao_ibama);

        a.push_back(shared_ptr<AveExotica>(new AveExotica(id, "Aves", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, tamanho_do_bico_cm, envergadura_das_asas, pais_origem, autorizacao_ibama)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função com menu para escolher se a ave é domestica, nativa ou exotica
void cadastrarAve(vector<shared_ptr<Animal>> &a) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "###################################################" << endl;
        cout << "###                 NOVA AVE                    ###" << endl;
        cout << "###################################################" << endl;
        cout << endl << "Escolha o tipo do novo mamifero: " << endl << endl;
        cout << "[1] - Domestica" << endl;
        cout << "[2] - Nativa" << endl;
        cout << "[3] - Exotica" << endl;
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
                    clear();
                    cadastrarAveDomestica(a);
                    pressToCont();
                    break;
                case 2:
                    clear();
                    cadastrarAveNativa(a);
                    pressToCont();
                    break;
                case 3:
                    clear();
                    cadastrarAveExotica(a);
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

//Função para cadastrar reptil domestico
void cadastrarReptilDomestico(vector<shared_ptr<Animal>> &a) {
    int id, tratador, veterinario;
    string nome, nome_cientifico, dieta, batismo, tipo_veneno;
    char sexo;
    double tamanho;
    bool venenoso;

    cout << "Digite as informaçoes do novo animal: " << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Animal>>::iterator it = find_if(a.begin(), a.end(), [&id](const shared_ptr<Animal> & obj) {return obj->getId() == id;});
    if( it != a.end() ) {
        cout << endl << "Já existe um animal cadastrado com esse ID" << endl << endl;
        cin.ignore();
    } else {
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Nome Cientifico: ";
        getline(cin, nome_cientifico);
        cout << "Sexo: ";
        cin >> sexo;
        cout << "Tamanho: ";
        cin >> tamanho;
        cout << "Dieta: ";
        cin.ignore();
        getline(cin, dieta);
        cout << "ID do tratador ( Digite 0 caso nao tenha tratador): ";
        cin >> tratador;
        cout << "ID do veterinario ( Digite 0 caso nao tenha veterinario ): ";
        cin >> veterinario;
        cout << "Nome de batismo: ";
        cin.ignore();
        getline(cin, batismo);
        cout << "Venenoso ([1] - Sim / [0] - Nao): ";
        cin >> venenoso;
        cout << "Tipo do veneno: ";
        cin.ignore();
        getline(cin, tipo_veneno);

        a.push_back(shared_ptr<Reptil>(new Reptil(id, "Reptilia", nome, nome_cientifico, sexo, tamanho, dieta, tratador, veterinario, batismo, venenoso, tipo_veneno)));

        cout << endl << "Novo animal cadastrado com sucesso!" << endl << endl;
    }
}

//Função com menu para escolher se o reptil é domestico, nativo ou exotico
void cadastrarReptil(vector<shared_ptr<Animal>> &a) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "###################################################" << endl;
        cout << "###                 NOVO REPTIL                 ###" << endl;
        cout << "###################################################" << endl;
        cout << endl << "Escolha o tipo do novo mamifero: " << endl << endl;
        cout << "[1] - Domestico" << endl;
        cout << "[2] - Nativo" << endl;
        cout << "[3] - Exotico" << endl;
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
                    clear();
                    cadastrarReptilDomestico(a);
                    pressToCont();
                    break;
                case 2:
                    clear();
                    //cadastrarMamiferoNativo(a);
                    pressToCont();
                    break;
                case 3:
                    clear();
                    //cadastrarMamiferoExotico(a);
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

//Função para cadastrar um novo animal
void cadastrarAnimal(vector<shared_ptr<Animal>> &a) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "########################################################" << endl;
        cout << "###                 NOVO ANIMAL                      ###" << endl;
        cout << "########################################################" << endl;
        cout << endl << "Escolha a classe do novo animal: " << endl << endl;
        cout << "[1] - Adicionar novo animal mamifero" << endl;
        cout << "[2] - Adicionar novo animal anfibio" << endl;
        cout << "[3] - Adicionar novo animal ave" << endl;
        cout << "[4] - Adicionar novo animal reptil" << endl;
        cout << endl;
        cout << "[0] - Sair" << endl << endl;

        if (error) {
            error = false;
            cout << "**Digite uma opcao valida!**" << endl;
        }
        cout << "Opcao: ";
        cin >> input;

        if (checarDigito(input)) {
            escolha = stoi(input);

            if (escolha >= 0 && escolha <= 4) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    clear();
                    cadastrarMamifero(a);
                    pressToCont();
                    break;
                case 2:
                    clear();
                    cadastrarAnfibio(a);
                    pressToCont();
                    break;
                case 3:
                    clear();
                    cadastrarAve(a);
                    pressToCont();
                    break;
                case 4:
                    clear();
                    cadastrarReptil(a);
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

//Menu de animais
void menuAnimal(vector<shared_ptr<Animal>> &a) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "########################################################" << endl;
        cout << "###                      ANIMAIS                     ###" << endl;
        cout << "########################################################" << endl;
        cout << endl << "Escolha uma das seguintes opcoes: " << endl << endl;
        cout << "[1] - Adicionar novo animal" << endl;
        cout << "[2] - Remover animal" << endl;
        cout << "[4] - Alterar dados de um animal" << endl;
        cout << "[5] - Consultar animal" << endl;
        cout << "[6] - Mostrar animais" << endl;
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

            if (escolha >= 0 && escolha <= 6) {
                switch (escolha) {
                case 0:
                    sair = true;
                    break;
                case 1:
                    clear();
                    cadastrarAnimal(a);
                    pressToCont();
                    break;
                case 2:
                    //
                    break;
                case 3:
                    //
                    break;
                case 4:
                    //
                    break;
                case 5:
                    //
                    break;
                case 6:
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

//Função para cadastrar um tratador
void novoTratador(vector<shared_ptr<Funcionario>> &f) {
    int id, idade, nivel_seguranca;
    char fator_rh;
    string nome, cpf, tipo_sanguineo, especialidade;
    
    cout << "Digite as informaçoes do novo tratador" << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Funcionario>>::iterator it = find_if(f.begin(), f.end(), [&id](const shared_ptr<Funcionario> & obj) {return obj->getId() == id;});
    if( it != f.end() ) {
        cout << endl << "Já existe um funcionario cadastrado com esse ID" << endl << endl;
    } else {
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
    }
    cin.ignore();
}

//Função para cadastrar um veterinario
void novoVeterinario(vector<shared_ptr<Funcionario>> &f) {
    int id, idade;
    char fator_rh;
    string nome, cpf, tipo_sanguineo, especialidade, crmv;

    cout << "Digite as informaçoes do novo tratador" << endl;
    cout << "ID: ";
    cin >> id;

    vector<shared_ptr<Funcionario>>::iterator it = find_if(f.begin(), f.end(), [&id](const shared_ptr<Funcionario> & obj) {return obj->getId() == id;});
    if( it != f.end() ) {
        cout << endl << "Já existe um funcionario cadastrado com esse ID" << endl << endl;
    } else {
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
    }
    cin.ignore();
}

//Função para remover um funcionario
void removerFuncionario(vector<shared_ptr<Funcionario>> &f) {
    int id;

    cout << "Digite o ID do funcionario: ";
    cin >> id;

    vector<shared_ptr<Funcionario>>::iterator it = find_if(f.begin(), f.end(), [&id](const shared_ptr<Funcionario> & obj) {return obj->getId() == id;});
    if( it != f.end() ) {
        f.erase(it);
        cout << "Funcionario removido com sucesso!" << endl;
    } else {
        cout << "Não existe funcionario com esse id cadastrado!" << endl;
    }
    cin.ignore();
}

//Função para alterar dados de um funcionario
void alterarFuncionario(vector<shared_ptr<Funcionario>> &f) {
    int id;        

    cout << "Digite o ID do funcionario: ";
    cin >> id;

    vector<shared_ptr<Funcionario>>::iterator it = find_if(f.begin(), f.end(), [&id](const shared_ptr<Funcionario> & obj) {return obj->getId() == id;});
    if( it != f.end() ) {
        f[std::distance(f.begin(), it)]->atualizarDados();
        cout << "Informacoes do funcionario atualizadas com sucesso!" << endl;
    } else {
        cout << "Não existe funcionario com esse id cadastrado!" << endl;
    }
    cin.ignore();
}

void consultarFuncionario(vector<shared_ptr<Funcionario>> &f) {
    int id;        

    cout << "Digite o ID do funcionario: ";
    cin >> id;

    vector<shared_ptr<Funcionario>>::iterator it = find_if(f.begin(), f.end(), [&id](const shared_ptr<Funcionario> & obj) {return obj->getId() == id;});
    if( it != f.end() ) {
        f[std::distance(f.begin(), it)]->mostrarDados();
    } else {
        cout << "Não existe funcionario com esse id cadastrado!" << endl;
    }
    cin.ignore();
}

//Funcao para mostrar os funcionarios de acordo com o tipo
void mostrarFuncionarios(vector<shared_ptr<Funcionario>> &f) {
    string input;
    int escolha;
    bool sair = false, error = false;

    //Loop para verificar se o input é uma opção válida e caso seja, realizer a operação referente a escolha
    do {
        clear();
        cout << endl << "#############################################################" << endl;
        cout << "###                      FUNCIONARIOS                     ###" << endl;
        cout << "#############################################################" << endl;
        cout << endl << "Escolha o tipo de funcionario: " << endl << endl;
        cout << "[1] - Tratador" << endl;
        cout << "[2] - Veterinario" << endl;
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
                default:
                    clear();
                    for (unsigned i = 0; i < f.size(); i++) {
                        f[i]->mostrarFuncionarios(escolha - 1);
                    }
                    cin.ignore();
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
        cout << "[4] - Alterar dados de um funcionario" << endl;
        cout << "[5] - Consultar funcionario" << endl;
        cout << "[6] - Mostrar funcionarios" << endl;
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

            if (escolha >= 0 && escolha <= 6) {
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
                case 5:
                    clear();
                    consultarFuncionario(f);
                    pressToCont();
                    break;
                case 6:
                    clear();
                    mostrarFuncionarios(f);
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
void menuPrincipal(vector<shared_ptr<Funcionario>> &f, vector<shared_ptr<Animal>> &a) {
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
                    menuAnimal(a);
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

    vector<shared_ptr<Animal>> animais;
    vector<shared_ptr<Funcionario>> funcionarios;

	lerDados(funcionarios, animais);

    menuPrincipal(funcionarios, animais);

	salvarDados(funcionarios, animais);

	return 0;
}