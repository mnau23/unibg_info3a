#include "Wide.h"
#ifndef FISHEYE_H_
#define FISHEYE_H_

class Fisheye: public Wide {
public:
	string focal;
	string diaphragm;
	Fisheye();
	Fisheye(string brandName);
	Fisheye(string brandName, string f, string d);
	~Fisheye(){};
	void print();
	float convertCurrency(float p);
};

#endif /* FISHEYE_H_ */
