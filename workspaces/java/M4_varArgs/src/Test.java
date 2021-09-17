import java.util.logging.Handler;

public class Test {

	static void print(String... s) {
		for (String a : s)
			System.out.print(a + " ");
		System.out.println();
	}

	static void foo(int a, Handler... handlers) {
	}

	// Cose che non si possono fare:
	// (Regola: un solo varargs e come ultimo argomento)
	// static void foo(Handler... handlers1, Handler... handlers2) {}
	// static void foo(Handler... handlers, int a) {}

	public static void main(String[] args) {
		print("Ciao");
		print("Ciao", "io", "amo", "Java");
		String s = "oggi";
		print("Dove", "sei", s);
	}
}