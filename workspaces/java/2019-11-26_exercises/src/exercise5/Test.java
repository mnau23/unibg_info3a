package exercise5;

public class Test {
	public static void main(String[] args) {
		SequenzaOrdinabile<Integer> seq = new SequenzaOrdinabile<Integer>();
		
		/*
		seq.insert("prova");
		seq.insert("prova5");
		seq.insert("prova4");
		*/
		
		seq.insert(4);
		seq.insert(3);
		seq.insert(6);
		
		seq.stampa();
		
		seq.bubbleSort();
		
		seq.stampa();
		
		SequenzaOrdinabile<Persona> pers = new SequenzaOrdinabile<>();
		
		pers.insert(new Studente("s1"));
		pers.insert(new Studente("s2"));
		pers.insert(new Studente("s3"));
		pers.insert(new Studente("s4"));
		pers.insert(new Persona("p1"));
		
		pers.stampa();
		
		Persona p1= new Persona("p1");
		Studente s1=new Studente("s1");
		p1.compareTo(s1);
		
		SequenzaUtils seq2 = new SequenzaUtils();
		seq2.insert(4);
		seq2.insert(3);
		seq2.insert(6);
		
		System.out.println(seq2.mezzo());
		
	}
}
