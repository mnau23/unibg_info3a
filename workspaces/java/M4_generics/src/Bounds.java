import java.util.ArrayList;
import java.util.List;

class Person { void stampaDati() {} }
class Student extends Person { }

public class Bounds {
	public static void main(String[] args) {
		
		// List<Object> lo1 = new ArrayList<String>(); 
		// Errore > accetta solo Object
		
		List<Object> lo2 = new ArrayList<Object>();
		
		// Lista veramente generica
		List<?> lo3 = new ArrayList<String>();
		lo3 = new ArrayList<Student>();
		
		printPrimaPersona(new ArrayList<Student>());
	}
	
//	static void printPersone(List<Person> p) {
//	static void printPersone(List<?> p) {
	static void printPrimaPersona(List<? extends Person> p) {
		p.get(0).stampaDati();
	}
	
}
