package visitor;

public class Test {
	public static void main(String[] args) {
		
		Rectangle r = new Rectangle();
		Translate t = new Translate();
		r.accept(t);
		
		Rectangle s = new Square();
		s.accept(t);	
	}
}
