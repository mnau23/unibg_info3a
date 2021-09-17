package exercise7;

import java.util.ArrayList;

public class Test {
	public static void main(String[] args) {
		
		// Creo dei componenti
		ComponenteComposto C = new ComponenteComposto();
		ComponenteComposto C1 = new ComponenteComposto();
		ComponenteComposto C2 = new ComponenteComposto();
		ComponenteComposto C3 = new ComponenteComposto();
		
		// Aggiungo a questi componenti dei vari componenti atomici
		C.ListaC.add(new Atomico());
		C.ListaC.add(new Atomico());
		C.ListaC.add(new Atomico());
		C.ListaC.add(new Atomico());
		C1.ListaC.add(new Atomico());
		C1.ListaC.add(new Atomico());
		C3.ListaC.add(C);
		
		// Per prova calcolo il prezzo ed il nome del componente C e C3
		PriceCalculator PC = new PriceCalculator();
		NameCalculator NC = new NameCalculator();
		System.out.println(C.accept(PC));
		System.out.println(C.accept(NC));
		System.out.println(C3.accept(PC));
		System.out.println(C3.accept(NC));
		
		// Creo una lista di componenti, con i 4 che ho
		// creato prima più + un componente atomico
		ArrayList<Componente> LC = new ArrayList<Componente>();
		LC.add(C);
		LC.add(C1);
		LC.add(C2);
		LC.add(C3);
		LC.add(new Atomico());
		
		// Calcolo il prezzo totale
		System.out.println(Componente.sommaCosto(LC));
	}
}
