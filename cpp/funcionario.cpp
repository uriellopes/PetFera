#include "../includes/funcionario.h"

Funcionario::Funcionario() {}

Funcionario::~Funcionario() {}

std::ostream& operator<< (std::ostream &o, Funcionario &f) {
    f.print(o);
    return o;
}