#ifndef Veterinario_H
#define Veterinario_H

#include "funcionario.h"

class Veterinario : public Funcionario {
private:
	string crmv;
public:
	Veterinario(int, string, string, int, string, char, string, string);
	~Veterinario();
};

#endif