#include <string>
using namespace std;
#ifndef LENS_H_
#define LENS_H_

class Lens {
public:
	string brandName;
	Lens();
	Lens(string brandName);
	virtual ~Lens();	// calls subclasses destructors
	virtual void print();
	virtual float convertCurrency(float p)=0;
};

#endif /* LENS_H_ */
