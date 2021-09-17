package exercise2;

public class Test {
	public static void main(String[] args) {
		char[] CF= "aaaaaaaaaaaaaaaa".toCharArray();
		char[] CF2= {'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'};
		
		Object p1 = new Persona("Name1","Surname1",CF);
		Persona p2 = new Persona("Name2","Surname2", CF2);
		
		boolean x = p1.equals(p2);
		
		System.out.println(x);
	}
}
