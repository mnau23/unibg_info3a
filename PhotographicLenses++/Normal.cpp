#include <iostream>
#include "Normal.h"
using namespace std;

// Empty constructor
Normal::Normal():Lens("Unknown brand"){
}

// Constructor
Normal::Normal(string brandName):Lens(brandName){
	Normal::focal = "Unknown";
	Normal::diaphragm = "Unknown";
	cout<<" > Normal";
}

// Constructor
Normal::Normal(string brandName, string f, string d):Lens(brandName){
	Normal::focal = f;
	Normal::diaphragm = d;
	cout<<" > Normal";
}

void Normal::print(){
	Lens::print();
	cout<<" is a normal."<<endl;
	cout<<"Focal: "<<Normal::focal<<endl;
	cout<<"Diaphragm: "<<Normal::diaphragm<<endl;
}

float Normal::convertCurrency(float p){
	cout<<"Currency (USD to EUR) using method from class Normal: "<<p/1.20<<" €."<<endl;
	return p/1.20;
}
