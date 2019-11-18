#include <iostream>
#include <vector>

class Parent {
protected:
	int id = 30;
public:
	virtual void print() = 0;
};  

void Parent::print() {
	std::cout << "Printing!";
}

class Type1 : public virtual Parent {
    protected:
    	int teste = 78;
    public:
    	virtual void print() = 0;
};

class Type1Filho : public virtual Type1 {
private:
	int asd = 80;
public:
	Type1Filho();
	Type1Filho(int a, int t);
	~Type1Filho();
	void print();

	friend std::ostream& operator<< (std::ostream &o, Type1Filho const t);
};

Type1Filho::Type1Filho() {

}

Type1Filho::Type1Filho(int a, int t) {
	asd = a;
	teste = t;
}

void Type1Filho::print() {
	std::cout << teste << "id " << id << "Tipo 1 filho" << asd << std::endl;
}

// std::ostream& operator<< (std::ostream &o, Type1Filho const t) {
// 	o << t.teste << "Tipo 1 filho" << t.asd << std::endl;
// 	return o;
// }

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
public:
	T* m_elementos; // Elementos armazenados na pilha
	int m_tamanho; // Qtde atual de elementos
	int m_capacidade; // Qtde Max de elementos
//public:
	Pilha (int n_capacidade = 50);
	~Pilha ();
	bool empty ();
	bool full ();
	T& top ();
	void push ( T novo );
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
void Pilha<T>::push ( T novo )
{
	m_tamanho = m_tamanho + 1;
	int newSize = m_tamanho;

	T *temp = new T[newSize];

	for(int i = 0; i < newSize; i++) {
		temp[i] = m_elementos[i];
		// std::cout << i << std::endl;
	}

	m_elementos = new T[newSize];

	for(int i = 0; i < newSize; i++) {
		m_elementos[i] = temp[i];
		//std::cout << i << std::endl;
	}

	m_elementos[m_tamanho - 1] = novo;

	//std::cout << novo << std::endl;

	delete[] temp;

	// if (full())
	// 	return 0;
	// m_elementos[m_tamanho++] =
	// novo;
	// return 1;
}

template <typename T>
T &Pilha<T>::operator[](int index) 
{ 
    if (index >= m_tamanho) 
    { 
        std::cout << "Array index out of bound, exiting" << index << std::endl; 
        exit(0); 
    }
    return m_elementos[index]; 
}


int main() {

	Pilha<Parent*> vec;

	//std::cout << vec.m_tamanho << std::endl;
	vec.push(new Type1Filho(20,20));
	//std::cout << vec.m_tamanho << std::endl;
	vec.push(new Type1Filho);
	//std::cout << vec.m_tamanho << std::endl;
	vec.push(new Type3);

	vec[0]->print();
	vec[1]->print();
	vec[2]->print();
	// vec[2]->print();

	//std::cout << vec.m_tamanho << std::endl;

	return 0;
}