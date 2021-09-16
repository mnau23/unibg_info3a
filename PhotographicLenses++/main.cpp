/*
==========================================================================================
Name        : PhotographicLenses++
Author      : Emanuele Perico
Version     : 1.0
Description : The scenario chosen for this project is that of photographic lenses:
			  making use of classes and inheritance, it is shown a small example
			  for distinguishing between the different existing categories.
==========================================================================================
*/

#include <iostream>
#include "Fisheye.h"
#include "Lens.h"
#include "Macro.h"
#include "Normal.h"
#include "Zoom.h"
#include "Wide.h"
using namespace std;

int main() {

	cout<<"Object 1 generated as: ";
	Normal lens1 = Normal("Brand1");
	lens1.print();
	cout<<endl;

	cout<<"Object 2 generated as: ";
	Zoom lens2 = Zoom("Brand2");
	lens2.print();
	cout<<endl;

	cout<<"Object 3 generated as: ";
	Normal lens3 = Normal("Brand3","50mm","f/1.8");
	lens3.print();
	lens3.convertCurrency(89.99);
	cout<<endl;

	cout<<"Object 4 generated as: ";
	Zoom lens4 = Zoom("Brand4",Zoom::telephoto,"100-400mm","f/4.5-6.3");
	lens4.print();
	lens4.convertCurrency(856.99);
	cout<<endl;

	cout<<"Object 5 generated as: ";
	Macro lens5 = Macro("Brand5","105mm","f/2.8");
	lens5.print();
	lens5.convertCurrency(905.99);
	cout<<endl;

	cout<<"Object 6 generated as: ";
	Macro lens6 = Macro("Brand6",Zoom::zoom,"17-70mm","f/2.8-4");
	lens6.print();
	lens6.convertCurrency(419.99);
	cout<<endl;

	cout<<"Object 7 generated as: ";
	Wide lens7 = Wide("Brand7","28mm","f/2.8");
	lens7.print();
	lens7.convertCurrency(91.99);
	cout<<endl;

	cout<<"Object 8 generated as: ";
	Fisheye lens8 = Fisheye("Brand8","16mm","f/2.8");
	lens8.print();
	lens8.convertCurrency(1039.99);
	cout<<endl;
	return 0;
}
