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

// void Type1::print() {
// 	std::cout << "Tipo 1" << std::endl;
// }

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

// template <typename T>
// class Pilha

int main() {

	std::vector<Parent*> vec;

	vec.push_back(new Type1Filho);
	vec.push_back(new Type2);
	vec.push_back(new Type3);

	vec[0]->print();
	vec[1]->print();
	vec[2]->print();

	std::cout << "ola" << std::endl;

	return 0;
}