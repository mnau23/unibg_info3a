#include <iostream>
using namespace std;

class C {
private:
	virtual void m() {
		cout<<"Metodo m di C privato"<<endl;
	}
public:
	void foo() {
		cout<<"foo "<<endl;
		m();
	}
};

class D: public C {
	int x;
private:
	virtual void m() {
		cout<<"Metodo m di D privato"<<endl;
	}
};

class E: private C {
};


int main() {
	C *pc = new C;
	pc->foo();
	delete pc;
	// Con polimorfismo
	C *pcd = new D;
	pcd->foo();
	delete pcd;
	// No sottotipazione
	// Errore: A* pc = new C;
	// s
	D d;
	C c = d;
}
