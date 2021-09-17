package tema_esame;

public class Test {
	public static void main(String[] args) {
		// (3 + 2) * 10
		Expression num1 = new NumExpr(3);
		Expression num2 = new NumExpr(2);
		Expression num3 = new NumExpr(10);
		Expression sum = new SumExpr(num1, num2);
		Expression prod = new ProdExpr(sum, num3);
		
		// punto 1
		System.out.println("Result of (3+2)*10: " + prod.evaluate());
		
		ToString ts = new ToString();
		CalcolaValore cv = new CalcolaValore();
		
		// punto 2
		System.out.println(prod.accept(ts));
		System.out.println(prod.accept(cv));
	}
}
