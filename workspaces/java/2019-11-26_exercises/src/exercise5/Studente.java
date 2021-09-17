package exercise5;

public class Studente extends Persona {
	
	Studente(String n) {
		super(n);
	}
	
	@Override
	public int compareTo(Studente arg0) {
		return arg0.nome.compareTo(this.nome);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "Studente " + nome;
	}
}
