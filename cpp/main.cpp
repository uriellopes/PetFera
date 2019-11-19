#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>

#include <sstream>
using std::stringstream;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include "../includes/animal.h"
#include "../includes/tratador.h"
#include "../includes/veterinario.h"

void lerDados(vector<Animal> &animais) {
    
    ifstream file_animais("animais.csv");

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
            animais.push_back(
            	Animal(stoi(values[0]), values[1], values[2], values[3], *values[4].c_str(), 
            		stod(values[5]), values[6], stoi(values[7]), stoi(values[8]), values[9])
            	);
        }
    }

    file_animais.close();
}

void salvarDados(vector<Animal> &animais) {

    ofstream file_animais("animais.csv");

    for (unsigned i = 0; i < animais.size(); i++) {
        file_animais << animais[i] << endl;
    }

    file_animais.close();
}

int main() {

	vector<Animal> animais;
	vector<Tratador> tratadores;
	vector<Veterinario> veterinarios;

	lerDados(animais);

	cout << animais[0] << endl;
	cout << animais[1] << endl;
	cout << animais[2] << endl;

	salvarDados(animais);

	return 0;
}