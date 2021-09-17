package exercise5;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class SequenzaOrdinabile<T extends Comparable<T>> {
	ArrayList<T> array=new ArrayList<>();

	public SequenzaOrdinabile() {
		// TODO Auto-generated constructor stub
	}

	void insert(T e) {
		array.add(e);
	}
	
	void stampa() {
		for(T c: array)
			System.out.println(c.toString());
	}
	
	@Override
	public String toString() {
		return super.toString();
	}
	
	public void bubbleSort() {
		boolean needNextPass = true;

		for(int k = 1; k < array.size() && needNextPass; k++) {
			// Array may be sorted and next pass not needed
			needNextPass = false;
			for(int i = 0; i < array.size() - k; i++) {
				if(array.get(i).compareTo(array.get(i+1)) > 0) {
					// Swap list[i] with list[i + 1]
					T temp = array.get(i);
					array.set(i, array.get(i+1));
					array.set(i+1, temp);
					needNextPass = true; // Next pass still needed
				}
			}
		}
	}
}
