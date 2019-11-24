#include "../includes/animal.h"

Animal::Animal() {}

Animal::~Animal() {}

std::ostream& operator<< (std::ostream &o, Animal &f) {
    f.print(o);
    return o;
}

int Animal::getId() {
    return id;
}

void Animal::mostrarAnimais(int t) {
    if( tipo == t ) {
        mostrarDados();
    }
}

int Animal::getIdTratador() {
    return tratador;
}

int Animal::getIdVeterinario() {
    return veterinario;
}