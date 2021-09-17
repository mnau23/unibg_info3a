#include <iostream>
using namespace std;

void foo5() {
	// Variabile static viene messa prima dello stack
	// e inizializzata solo la prima volta, non ogni volta
	static int x = 0;
	cout<<x<<endl;
	x += 5;
}

int main() {
	foo5();
	foo5();
	foo5();
}
