package tema_esame;

interface Visitable {
	// metodo per usare il visitor
	Object accept(Visitor v);
}
