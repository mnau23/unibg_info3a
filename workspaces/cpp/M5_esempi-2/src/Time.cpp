#include "Time.hpp"
#include <iostream>
using namespace std;


Time::Time() {
	hour = minute = second = 0;
}

// Costruttore ora
/*Time::Time(int h) {
	hour = h;
	minute = second = 0;
}*/

// Costruttore con initializer list
Time::Time(int h, int m, int s): hour(h), minute(m), second(s) {
}

Time::Time(int h): Time(h,0,0) {
}

void Time::printStandard() const {
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}
