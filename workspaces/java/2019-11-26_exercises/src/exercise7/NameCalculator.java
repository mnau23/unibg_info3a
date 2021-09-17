package exercise7;

/*
 * Visitor: permette di calcolare il Nome di un componente che lo accetta
 */
class NameCalculator implements Visitor<String> {

	public String visit(ComponenteComposto c) {
		String res;
		res = "[";
		// Scelgo quale metodo visit chiamare in funzione
		// della classe a cui appartiene runtime l'oggetto
		for (int i = 0; i < c.ListaC.size(); i++) {
			res += c.ListaC.get(i).accept(this);
		}
		res += "]";
		return res;
	}

	public String visit(Atomico c) {
		return c.nome;
	}

}