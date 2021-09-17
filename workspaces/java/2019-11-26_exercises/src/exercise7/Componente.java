package exercise7;

import java.util.ArrayList;

public abstract class Componente implements Visitable {

	/*
	 * Metodo "ereditato" dall'interfaccia Visitable
	 * che permette al visitor di accedere
	 * alle informazioni di questo oggetto
	 */
	public abstract <T> T accept(Visitor<T> v);

	/*
	 * Metodo statico per calcolare la somma dei costi di una lista
	 * di componenti per fare in modo che accetti sia Componenti
	 * che Atomici la definisco con le wildcards, imponendo che
	 * la classe passata deve essere una sottoclasse di Componente
	 */
	static int sommaCosto(ArrayList<? extends Componente> lista) {
		int somma = 0;
		
		// Definisco il visitor che potrà  calcolare i prezzi
		PriceCalculator PC = new PriceCalculator();
		
		for (int i = 0; i < lista.size(); i++) {
			somma += lista.get(i).accept(PC);
		}
		return somma;
	}
}
