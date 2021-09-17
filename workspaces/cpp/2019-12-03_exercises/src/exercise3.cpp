#include <iostream>
using namespace std;

template<int nome_size> class Studente {
private:
	char nome[nome_size];
};

template<typename T> T massimo(T a, T b) {
	return a > b ? a : b;
};

class A {
};

int main() {
	int y = massimo(3, 4);
	cout<<"MAX: massimo(3,4) = " <<y<<endl;
	cout<<endl;

	string s1 = "pippo";
	string s2 = "pluto";
	cout<<"MAX: massimo(\'pippo\',\'pluto\') = "<<massimo(s1, s2)<<endl;
	cout<<endl;

	/* Error
	 * A a1, a2;
	 * cout<<massimo(a1,a2)<<endl;
	 * cout<<endl;
	 */

	return 0;
}
