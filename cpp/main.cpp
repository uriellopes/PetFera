#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../includes/animal.h"
#include "../includes/tratador.h"
#include "../includes/veterinario.h"

void lerDados(std::vector<Animal> &animais) {
    
    std::ifstream file_animais("animais.csv");

    std::vector<std::string> values;
    std::string line, value;

    while(!file_animais.eof()) {
        getline(file_animais, line);
        if ( !line.empty() ) {
            std::stringstream temp(line);
            values.clear();
            while(getline(temp, value, ';')) {
                values.push_back(value);
            }
            animais.push_back(Animal(stoi(values[0])));
        }
    }

    file_animais.close();
}

int main() {

	std::vector<Animal> animais;
	std::vector<Tratador> tratadores;
	std::vector<Veterinario> veterinarios;

	lerDados(animais);

	std::cout << animais[0].getId() << std::endl;
	std::cout << animais[1].getId() << std::endl;
	std::cout << animais[2].getId() << std::endl;

	return 0;
}