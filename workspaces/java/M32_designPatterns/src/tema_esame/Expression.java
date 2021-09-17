package tema_esame;

abstract class Expression implements Visitable {	
	abstract int evaluate();
}

// numero
class NumExpr extends Expression {
	int value;
	
	// costruttore
	NumExpr(int val) {
		value = val;
	}
	
	@Override
	int evaluate() {
		return value;
	}

	// metodo per usare il visitor
	@Override
	public Object accept(Visitor v) {
		return v.visit(this);
	}
}

// prodotto
class ProdExpr extends Expression {
	Expression first, second;
	
	// costruttore
	ProdExpr(Expression a, Expression b) {
		first = a;
		second = b;
	}

	@Override
	int evaluate() {
		return first.evaluate() * second.evaluate();
	}

	// metodo per usare il visitor
	@Override
	public Object accept(Visitor v) {
		return v.visit(this);
	}
}

// somma
class SumExpr extends Expression {
	Expression first, second;
	
	// costruttore
	SumExpr(Expression a, Expression b) {
		first = a;
		second = b;
	}

	@Override
	int evaluate() {
		return first.evaluate() + second.evaluate();
	}

	// metodo per usare il visitor
	@Override
	public Object accept(Visitor v) {
		return v.visit(this);
	}
}
