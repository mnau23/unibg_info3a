#include <iostream>
using namespace std;

class A {
public:
	virtual ~A() {
		cout<<"A distrutto"<<endl;
	}
};

class B: public A {
	~B() {
		cout<<"B distrutto"<<endl;
	}
};


int main() {
	A *pa = new B;
	delete pa;
	return 0;
}
