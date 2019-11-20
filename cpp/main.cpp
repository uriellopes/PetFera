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

    // vector<string> values;
    // string line, value;

    // while(!file_animais.eof()) {
    //     getline(file_animais, line);
    //     if ( !line.empty() ) {
    //         stringstream temp(line);
    //         values.clear();
    //         while(getline(temp, value, ';')) {
    //             values.push_back(value);
    //         }
    //         animais.push_back(
    //         	Animal(stoi(values[0]), values[1], values[2], values[3], *values[4].c_str(), 
    //         		stod(values[5]), values[6], stoi(values[7]), stoi(values[8]), values[9])
    //         	);
    //     }
    // }

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

	tratadores.push_back(Tratador(1,"João Alberto","007.404.200-98",45,"AB",'-',"Répteis e Aves",1));
	veterinarios.push_back(Veterinario(2,"Daniel Oscar","123.456.789-10",30,"O",'+',"Felinos","CRMV-GO 0406"));

	salvarDados(tratadores, veterinarios);

	return 0;
}