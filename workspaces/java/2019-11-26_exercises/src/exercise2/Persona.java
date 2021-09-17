package exercise2;

import java.util.Arrays;

public class Persona {
	String nome;
	String cognome;
	char[] CF = new char[16];

	public Persona(String nome, String cognome, char[] CF) {
		this.nome = nome;
		this.cognome = cognome;
		this.CF = CF;
	}

	public boolean equals(Persona p) {
		System.out.println("Using equals(Persona)...");
		return Arrays.equals(p.CF, CF);
		/*if (p.CF.equals(CF))
		 * return true;
		 * //se uso equals di object anche se i CF sono uguali il risultato è false.
		return false;*/
	}
	
	@Override
	public boolean equals(Object obj) {
		if(obj instanceof Persona) // Istanza instanceof
			return equals((Persona) obj);
		return super.equals(obj);
	}
}
