#include "Normal.h"
#include "Zoom.h"
#ifndef MACRO_H_
#define MACRO_H_

class Macro: public Normal, public Zoom {
public:
	string focal;
	string diaphragm;
	bool type = false;	// false (0) > Normal, true (1) > Zoom
	Macro();
	Macro(string brandName);
	Macro(string brandName, enum Type zType);
	Macro(string brandName, string f, string d);
	Macro(string brandName, enum Type zType, string f, string d);
	~Macro();
	void print();
	float convertCurrency(float p);
};

#endif /* MACRO_H_ */
