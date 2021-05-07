#include <iostream>
#include "Fisheye.h"
using namespace std;

// Empty constructor
Fisheye::Fisheye():Wide(){
}

// Constructor
Fisheye::Fisheye(string brandName):Lens(brandName), Wide(brandName){
	cout<<" > Fisheye";
}

// Constructor
Fisheye::Fisheye(string brandName, string f, string d):Lens(brandName), Wide(brandName, f, d){
	Fisheye::focal = f;
	Fisheye::diaphragm = d;
	cout<<" > Fisheye";
}

void Fisheye::print(){
	Lens::print();
	cout<<" is a wide-angle and fish-eye."<<endl;
	cout<<"Focal: "<<Fisheye::focal<<endl;
	cout<<"Diaphragm: "<<Fisheye::diaphragm<<endl;
}

float Fisheye::convertCurrency(float p){
	cout<<"Currency (USD to EUR) using method from class Fisheye: "<<p/1.20<<" €."<<endl;
	return p/1.20;
}
