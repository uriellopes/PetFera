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
            animais.push_back(Animal(stoi(values[0])));
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

	cout << animais[0].getId() << endl;
	cout << animais[1].getId() << endl;
	cout << animais[2].getId() << endl;

	salvarDados(animais);

	return 0;
}