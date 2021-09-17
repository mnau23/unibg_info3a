public class Main {
	static void leggiDatabase() {
		Database db = new Database();
		// ...
	}

	public static void main(String[] args) {
		leggiDatabase();
		Runtime.getRuntime().gc(); // Forza il distruttore Finalize
		// while (true);
	}
}