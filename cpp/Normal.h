#include "Lens.h"
#ifndef NORMAL_H_
#define NORMAL_H_

class Normal: public virtual Lens {
public:
	string focal;
	string diaphragm;
	Normal();
	Normal(string brandName);
	Normal(string brandName, string f, string d);
	~Normal(){};
	void print();
	float convertCurrency(float p);
};

#endif /* NORMAL_H_ */
