package tema_esame;

// qui vengono rappresentate le operazioni
interface Visitor {
	Object visit(NumExpr n);
	Object visit(SumExpr s);
	Object visit(ProdExpr p);
}

class CalcolaValore implements Visitor {

	@Override
	public Integer visit(NumExpr n) {
		return n.value;
	}

	@Override
	public Integer visit(SumExpr s) {
		return (Integer)s.first.accept(this) + (Integer)s.second.accept(this);
	}

	@Override
	public Integer visit(ProdExpr p) {
		return (Integer)p.first.accept(this) * (Integer)p.second.accept(this);
	}
}

// espressione e restituisce la stringa
class ToString implements Visitor {

	@Override
	public Object visit(NumExpr n) {
		return String.valueOf(n.value);
	}

	@Override
	public Object visit(SumExpr s) {
		return s.first.accept(this) + "+" + s.second.accept(this);
	}

	@Override
	public Object visit(ProdExpr p) {
		return p.first.accept(this) + "*" + p.second.accept(this);
	}
}