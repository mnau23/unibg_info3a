#include "Lens.h"
#ifndef WIDE_H_
#define WIDE_H_

class Wide: public virtual Lens {
public:
	string focal;
	string diaphragm;
	Wide();
	Wide(string brandName);
	Wide(string brandName, string f, string d);
	~Wide(){};
	void print();
	float convertCurrency(float p);
};

#endif /* WIDE_H_ */
