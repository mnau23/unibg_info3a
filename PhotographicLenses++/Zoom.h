#include "Lens.h"
#ifndef ZOOM_H_
#define ZOOM_H_

class Zoom: private virtual Lens {
public:
	enum Type {zoom=0, telephoto=1, supertelephoto=2};
	string enumType;
	string focal;
	string diaphragm;
	Zoom();
	Zoom(string brandName);
	Zoom(string brandName, enum Type zType);
	Zoom(string brandName, enum Type zType, string f, string d);
	~Zoom(){};
	void print();
	float convertCurrency(float p);
};

#endif /* ZOOM_H_ */
