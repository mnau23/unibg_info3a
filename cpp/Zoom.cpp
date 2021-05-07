#include <iostream>
#include <string>
#include "Lens.h"
#include "Zoom.h"
using namespace std;

// Empty constructor
Zoom::Zoom():Lens("Unknown brand"){
}

// Constructor
Zoom::Zoom(string brandName):Lens(brandName){
	Zoom::enumType = "Unknown";
	Zoom::focal = "Unknown";
	Zoom::diaphragm = "Unknown";
	cout<<" > Zoom";
}

// Constructor
Zoom::Zoom(string brandName, enum Zoom::Type zType):Lens(brandName){
	switch (zType) {
	case zoom:
		Zoom::enumType = "zoom";
		break;
	case telephoto:
		Zoom::enumType = "telephoto";
		break;
	case supertelephoto:
		Zoom::enumType = "supertelephoto";
		break;
	}
	Zoom::focal = "Unknown";
	Zoom::diaphragm = "Unknown";
	cout<<" > Zoom";
}

// Constructor
Zoom::Zoom(string brandName, enum Type zType, string f, string d):Lens(brandName){
	switch (zType) {
	case zoom:
		Zoom::enumType = "zoom";
		break;
	case telephoto:
		Zoom::enumType = "telephoto";
		break;
	case supertelephoto:
		Zoom::enumType = "supertelephoto";
		break;
	}
	Zoom::focal = f;
	Zoom::diaphragm = d;
	cout<<" > Zoom";
}

void Zoom::print(){
	Lens::print();
	cout<<" is a zoom."<<endl;
	cout<<"Type: "<<Zoom::enumType<<endl;
	cout<<"Focal: "<<Zoom::focal<<endl;
	cout<<"Diaphragm: "<<Zoom::diaphragm<<endl;
}

float Zoom::convertCurrency(float p){
	cout<<"Currency (USD to EUR) using method from class Zoom: "<<p/1.20<<" €."<<endl;
	return p/1.20;
}
