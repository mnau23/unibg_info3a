package exercise5;

public class Persona implements Comparable<Persona> {
	String nome;
	
	Persona(String n) {
		this.nome = n;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	@Override
	public int compareTo(Persona p) {
		return p.nome.compareTo(this.nome);
	}
	
	public int compareTo(Studente arg0) {
		// TODO Auto-generated method stub
		return 0;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "Persona " + nome;
	}
}
