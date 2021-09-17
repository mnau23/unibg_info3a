package exercise7;

/*
 * Visitor: permette di calcolare il Prezzo di un componente che lo accetta
 */
class PriceCalculator implements Visitor<Integer> {

	public Integer visit(ComponenteComposto c) {
		int sum = 0;
		// Scelgo quale metodo visit chiamare in funzione
		// della classe a cui appartiene runtime l'oggetto
		for (int i = 0; i < c.ListaC.size(); i++) {
			sum += c.ListaC.get(i).accept(this);
		}
		return sum;
	}

	public Integer visit(Atomico c) {
		return c.prezzo;
	}
}