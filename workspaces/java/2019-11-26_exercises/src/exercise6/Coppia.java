package exercise6;

class Coppia<A extends Comparable<A>, B> {
	A a;
	B b;

	Coppia(A a, B b) {
		this.a = a;
		this.b = b;
	}
}