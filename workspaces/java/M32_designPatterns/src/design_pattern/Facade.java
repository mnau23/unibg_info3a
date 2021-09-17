package design_pattern;

class CPU {
	int freq;
}

class RAM {
	double quantity;
}

// Without Facade
class ComputerNF {
	private CPU cpu;
	private RAM ram;
	
	CPU getCPU() { return cpu; }
	RAM getRAM() { return ram; }
}

// With Facade
class ComputerFacade {
	private CPU cpu;
	private RAM ram;
	
	double getRAMquantity() {
		return ram.quantity;
	}
	
	int CPUfreq() {
		return cpu.freq;
	}
}


public class Facade {
}
