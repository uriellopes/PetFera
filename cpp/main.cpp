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

void salvarDados(vector<shared_ptr<Funcionario>> &f) {

    ofstream file_funcionarios("funcionarios.csv");

    for (unsigned i = 0; i < f.size(); i++) {
        file_funcionarios << *f[i] << endl;
    }

    file_funcionarios.close();
}

int main() {

    vector<shared_ptr<Funcionario>> funcionarios;

	lerDados(funcionarios);

	salvarDados(funcionarios);

	return 0;
}