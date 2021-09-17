#include <iostream>
using namespace std;

class Studente {
public:
	// virtual method
	virtual void getCorso() {
		cout<<"Studente.getCorso"<<endl;
	}

	// non-virtual method
	void getName() {
		cout<<"Studente.getName"<<endl;
	}
};

class StudenteLS: private Studente {
public:
	// virtual method
	virtual void getCorso() {
		cout<<"StudenteLS.getCorso"<<endl;
	}

	// non-virtual method
	void getName() {
		cout<<"StudenteLS.getName"<<endl;
	}
};


int main() {
	Studente *s11 = new Studente;
	s11->getCorso();
	s11->getName();
	printf("\n");

	/* Error: 'Studente' is an inaccessible base of 'StudenteLS'
	Studente *s12 = new StudenteLS;
	s12->getCorso();
	s12->getName();
	printf("\n");*/

	/* Error: invalid conversion
	StudenteLS* s21 = new Studente;
	s21->getCorso();
	s21->getName();
	printf("\n");*/

	StudenteLS *s22 = new StudenteLS;
	s22->getCorso();
	s22->getName();
	printf("\n");

	return 0;
}
