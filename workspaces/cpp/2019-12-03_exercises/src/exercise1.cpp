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

class StudenteLS: public Studente {
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

class StudenteIL: public Studente {
public:
	// virtual method
	virtual void getCorso() {
		cout<<"StudenteIL.getCorso"<<endl;
	}

	// non-virtual method
	void getName() {
		cout<<"StudenteIL.getName"<<endl;
	}
};


int main() {
	Studente *s11 = new Studente;
	s11->getCorso();
	s11->getName();
	printf("\n");

	Studente *s12 = new StudenteLS;
	s12->getCorso();
	s12->getName();
	printf("\n");

	Studente *s13 = new StudenteIL;
	s13->getCorso();
	s13->getName();
	printf("\n");

	/* Error: invalid conversion
	StudenteLS* s21 = new Studente;
	s21->getCorso();
	s21->getName();
	printf("\n");*/

	StudenteLS *s22 = new StudenteLS;
	s22->getCorso();
	s22->getName();
	printf("\n");

	/* Error: cannot convert in initialization
	StudenteLS* s23 = new StudenteIL;
	s23->getCorso();
	s23->getName();
	printf("\n");*/

	/* Error: invalid conversion
	StudenteIL* s31 = new Studente;
	s31->getCorso();
	s31->getName();
	printf("\n");*/

	/* Error: cannot convert in initialization
	StudenteIL* s32 = new StudenteLS;
	s32->getCorso();
	s32->getName();
	printf("\n");*/

	StudenteIL *s33 = new StudenteIL;
	s33->getCorso();
	s33->getName();
	printf("\n");

	return 0;
}
