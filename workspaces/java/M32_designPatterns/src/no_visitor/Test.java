package no_visitor;

public class Test {
	public static void main(String[] args) {
		Rectangle r = new Rectangle();
		Translate t = new Translate();
		t.process(r);
		// Translating rectangle
		Rectangle s = new Square();
		t.process(s);
	}
}
