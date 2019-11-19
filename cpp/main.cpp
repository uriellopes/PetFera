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

class TesteType {
	protected:
		int meuteste = 10;
	public:
		int getTeste();
};

int TesteType::getTeste() {
	return meuteste;
}

class Type1Filho : public virtual Type1, public virtual TesteType {
private:
	int asd = 80;
public:
	Type1Filho();
	Type1Filho(int a, int t);
	~Type1Filho();
	void print();
};

Type1Filho::Type1Filho() {

}

Type1Filho::Type1Filho(int a, int t) {
	asd = a;
	teste = t;
}

void Type1Filho::print() {
	std::cout << teste << "id " << id << "Tipo 1 filho" << asd << " " << getTeste() << std::endl;
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

int main() {

	std::vector<Parent*> vec;

	vec.push_back(new Type1Filho(20,20));
	vec.push_back(new Type1Filho);
	vec.push_back(new Type3);

	vec[0]->print();
	vec[1]->print();
	vec[2]->print();

	return 0;
}