#include <iostream>
#include "Lens.h"
using namespace std;

// Empty constructor
Lens::Lens(){
	cout<<"Lens";
}

// Constructor
Lens::Lens(string brandName):brandName(brandName){
	Lens::brandName = brandName;
	cout<<"Lens";
}

// Destructor
Lens::~Lens(){
}

// Virtual method (needs override)
void Lens::print(){
	cout<<endl<<Lens::brandName<<" lens";
}

// Virtual method (needs override)
float Lens::convertCurrency(float p){
	return 0;
}
