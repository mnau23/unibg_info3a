#include <iostream>

class A {
	int* ptr;
public:
	A() {
		std::cout<<"A creato"<<std::endl;
		ptr = new int[50];
	}
	~A() {
		std::cout<<"A distrutto"<<std::endl;
		delete [] ptr;
	}
};

void foo() {
	A a;
	std::cout<<"Fine foo"<<std::endl;
}

int main() {
	foo();
	int i = 9;
	int *pi = &i;

	// Sbagliato: non fare delete di un puntatore sullo stack
	delete pi;

	// Da dangling a NULL
	pi = NULL;

	*pi = 90;
	std::cout<<"Fine main"<<std::endl;

	return 0;
}
