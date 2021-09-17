package exercise1;
public class Test {
	public static void main(String[] args) {
		int h = 6;
		L l = new M();
		
		l.print(h);
		// Viene svolto il metodo della classe L -> stampa L
		
		// Per modificare il binding si deve cambiare la segnatura
		// della funzione print di M da int a double
	}
}
