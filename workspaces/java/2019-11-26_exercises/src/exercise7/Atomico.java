package exercise7;

/*
 * Atomico: sottoclasse di Componente, anch'essa Visitable
 */
class Atomico extends Componente implements Visitable {
	
	// Forzo il prezzo a 10 se il componente è atomico
	int prezzo = 10;
	
	// Forzo il nome a C se il componente è atomico
	String nome = "C";

	/*
	 * Metodo "ereditato" dall'interfaccia Visitable,
	 * che permette al visitor di accedere
	 * alle informazioni di questo oggetto
	 */
	public <T> T accept(Visitor<T> v) {
		return v.visit(this);
	}
}