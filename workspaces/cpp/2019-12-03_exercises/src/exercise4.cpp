#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	vector<int> powers2;

	// Fill a vector with the first 10 powers of 2
	for(int i=0; i < 10; i++)
		powers2.push_back(pow(2, i+1));

	// Print it in ascending order
	vector<int>::iterator iter;
	cout<<"Ascending order:"<<endl;
	for(iter=powers2.begin(); iter != powers2.end(); ++iter)
		cout<<*iter<<' ';

	cout<<endl<<endl;

	// Print it in descending order
	vector<int>::reverse_iterator revIter;
	cout<<"Descending order:"<<endl;
	for(revIter=powers2.rbegin(); revIter != powers2.rend(); ++revIter)
		cout<<*revIter<<' ';

	return 0;

}
