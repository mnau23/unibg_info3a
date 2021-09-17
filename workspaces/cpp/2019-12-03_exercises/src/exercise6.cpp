#include <iostream>
#include<vector>
using namespace std;

class Studente {
public:
	// virtual method
	virtual void getCorso(){
		cout<<"Studente.getCorso"<<endl;
	}

	// non-virtual method
	void getName(){
		cout<<"Studente.getName"<<endl;
	}
};

class StudenteLS: public Studente {
public:
	// virtual method
	virtual void getCorso(){
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
	cout<<endl<<"---Example 1---"<<endl;
	vector<Studente*> vect;

	Studente* s11 = new Studente;
	vect.push_back(s11);

	StudenteLS* s12 = new StudenteLS;
	vect.push_back(s12);

	StudenteIL* s13 = new StudenteIL;
	vect.push_back(s13);

	for(unsigned i=0; i<vect.size(); i++) {
		// Calls the methods of the created object type
		vect.at(i)->getCorso();
		vect.at(i)->getName();
	}

	cout<<endl<<"---Example 2---"<<endl;
	vector<Studente> vect2;
	Studente s21;
	vect2.push_back(s21);

	StudenteLS s22;
	vect2.push_back(s22);

	StudenteIL s23;
	vect2.push_back(s23);

	for(unsigned i=0; i < vect2.size(); i++) {
		// Calls the methods of class 'Studente' (because of vector<Studente>)
		vect2.at(i).getCorso();
		vect2.at(i).getName();
	}

	return 0;
}
