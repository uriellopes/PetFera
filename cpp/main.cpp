#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include "../includes/tratador.h"
#include "../includes/veterinario.h"

void lerDados(vector<Tratador> &t, vector<Veterinario> &v) {
    
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
                t.push_back(Tratador(stoi(values[1]), values[2], values[3], stoi(values[4]), values[5], *values[6].c_str(), values[7], stoi(values[8])));
                break;
            case 1:
                v.push_back(Veterinario(stoi(values[1]), values[2], values[3], stoi(values[4]), values[5], *values[6].c_str(), values[7], values[8]));
                break;
            }
        }
    }

    file_animais.close();
}

void salvarDados(vector<Tratador> &t, vector<Veterinario> &v) {

    ofstream file_funcionarios("funcionarios.csv");

    for (unsigned i = 0; i < t.size(); i++) {
        file_funcionarios << t[i] << endl;
    }

    for (unsigned i = 0; i < v.size(); i++) {
        file_funcionarios << v[i] << endl;
    }

    file_funcionarios.close();
}

int main() {

	vector<Tratador> tratadores;
	vector<Veterinario> veterinarios;

	lerDados(tratadores, veterinarios);

	salvarDados(tratadores, veterinarios);

	return 0;
}