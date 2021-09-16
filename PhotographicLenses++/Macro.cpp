#include <iostream>
#include "Macro.h"
#include "Normal.h"
#include "Zoom.h"
using namespace std;

// Empty constructor
Macro::Macro():Normal(), Zoom(){
	cout<<endl<<"Using constructor from class Normal.";
}

// Constructor
Macro::Macro(string brandName):Lens(brandName), Normal(brandName), Zoom(brandName){
	cout<<endl<<"Using constructor from class Normal.";
}

// Constructor
Macro::Macro(string brandName, string f, string d):Lens(brandName), Normal(brandName, f, d){
	cout<<" > Macro";
}

// Constructor
Macro::Macro(string brandName, enum Type zType):Lens(brandName), Zoom(brandName, zType){
	Macro::type = true;
	cout<<" > Macro";
}

// Constructor
Macro::Macro(string brandName, enum Type zType, string f, string d):Lens(brandName), Zoom(brandName, zType, f, d){
	Macro::type = true;
	cout<<" > Macro";
}

// Destructor
Macro::~Macro(){
}

void Macro::print(){
	if(type)
		Zoom::print();
	else
		Normal::print();
	cout<<"It is a macro."<<endl;
}

float Macro::convertCurrency(float p){
	cout<<"Currency (USD to EUR) using method from class Macro: "<<p/1.20<<" €."<<endl;
	return p/1.20;
}
