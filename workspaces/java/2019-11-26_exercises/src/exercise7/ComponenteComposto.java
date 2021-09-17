package exercise7;

import java.util.ArrayList;

/*
 * ComponenteComposto: contiene un ArrayList nella quale
 * vengono messi tutti i componenti (o atomici)
 * di cui è composto il componente corrente
 */
class ComponenteComposto extends Componente {

	ArrayList<Componente> ListaC = new ArrayList<Componente>();

	/*
	 * Metodo "ereditato" dall'interfaccia Visitable
	 * che permette al visitor di accedere
	 * alle informazioni di questo oggetto
	 */
	public <T> T accept(Visitor<T> v) {
		return v.visit(this);
	}

}