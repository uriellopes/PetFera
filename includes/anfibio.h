#include "animal.h"

class Anfibio : public Animal {
protected:
	int total_de_mudas;
	string ultima_muda;
public:
	Anfibio(int, string, string, string, char, double, string, int, int, string, int, string);
	~Anfibio();
};