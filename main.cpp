#include <iostream>
#include <vector>

class Parent {
private:
	int id;
public:
	virtual void print() = 0;
};  

void Parent::print() {
	std::cout << "Printing!";
}

class Type1 : public Parent {
    protected:
    	int teste;
    public:
    	virtual void print() = 0;
};

class Type1Filho : public Type1 {
private:
	int asd;
public:
	void print();
};

void Type1Filho::print() {
	teste = 78;
	asd = 80;
	std::cout << teste << "Tipo 1 filho" << asd << std::endl;
}

class Type2 : public Parent {
	private:
		int teste2;
	public:
		void print();
};

void Type2::print() {
	std::cout << "Tipo 2" << std::endl;
}

class Type3 : public Parent {
private:
	int teste3;
public:
    void print();
};

void Type3::print() {
	std::cout << "Tipo 3" << std::endl;
}

template <typename T>
class Pilha {
private:
	T* m_elementos; // Elementos armazenados na pilha
	int m_tamanho; // Qtde atual de elementos
	int m_capacidade; // Qtde Max de elementos
public:
	Pilha (int n_capacidade = 50);
	~Pilha ();
	bool empty ();
	bool full ();
	T& top ();
	int push ( T novo );
	int pop ();
	int size();
	T &operator[] (int);
};

template <typename T>
Pilha<T>::Pilha (int n_capacidade):
m_tamanho(0), m_capacidade(n_capacidade)
{
	m_elementos = new T[n_capacidade];
}
template <typename T>
Pilha<T>::~Pilha ()
{
	delete [] m_elementos;
}

template <typename T>
bool Pilha<T>::full ()
{
	return m_tamanho == m_capacidade;
}

template <typename T>
int Pilha<T>::push ( T novo )
{
	if (full())
		return 0;
	m_elementos[m_tamanho++] =
	novo;
	return 1;
}

template <typename T>
T &Pilha<T>::operator[](int index) 
{ 
    if (index >= m_tamanho) 
    { 
        std::cout << "Array index out of bound, exiting"; 
        exit(0); 
    } 
    return m_elementos[index]; 
}


int main() {

	Pilha<Parent*> vec;

	vec.push(new Type1Filho);
	// vec.push(new Type2);
	// vec.push(new Type3);

	vec[0]->print();
	// vec[1]->print();
	// vec[2]->print();

	std::cout << "ola" << std::endl;

	return 0;
}