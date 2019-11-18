#ifndef VETERINARIO_H
#define VETERINARIO_H

#include<iostream>
#include"funcionario.h"

using namespace std;

class Veterinario : public Funcionario {
	public:
		Veterinario();
		Veterinario(int id);
};



#endif
