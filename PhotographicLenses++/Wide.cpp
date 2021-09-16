#include <iostream>
#include "Wide.h"
using namespace std;

// Empty constructor
Wide::Wide():Lens("Unknown brand"){
}

// Constructor
Wide::Wide(string brandName):Lens(brandName){
	Wide::focal = "Unknown";
	Wide::diaphragm = "Unknown";
	cout<<" > Wide";
}

// Constructor
Wide::Wide(string brandName, string f, string d):Lens(brandName){
	Wide::focal = f;
	Wide::diaphragm = d;
	cout<<" > Wide";
}

void Wide::print(){
	Lens::print();
	cout<<" is a wide-angle."<<endl;
	cout<<"Focal: "<<Wide::focal<<endl;
	cout<<"Diaphragm: "<<Wide::diaphragm<<endl;
}

float Wide::convertCurrency(float p){
	cout<<"Currency (USD to EUR) using method from class Wide: "<<p/1.20<<" €."<<endl;
	return p/1.20;
}
