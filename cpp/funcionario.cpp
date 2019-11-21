#include "../includes/funcionario.h"

Funcionario::Funcionario() {}

Funcionario::~Funcionario() {}

std::ostream& operator<< (std::ostream &o, Funcionario &f) {
    f.print(o);
    return o;
}

int Funcionario::getId() {
    return id;
}

void Funcionario::mostrarFuncionarios(int f) {
    if( funcao == f ) {
        mostrarDados();
    }
}