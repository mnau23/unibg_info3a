#include <iostream>
#include <map>
using namespace std;

map<string, int> insertValues(){
	map<string, int> m;
	string n;
	int g;
	bool flag = true;

	// Examples: ("n1", 18) - ("n2", 22) - ("n3", 26) - ("n4", 30)
	while(flag) {
		cout<<"Write name... ";
		cin>>n;
		cout<<"Write grade... ";
		cin>>g;
		m.insert(map<string, int>::value_type(n,g));
		cout<<"Continue? (yes 1 / no 0)... ";
		cin>>flag;
	}

	return m;
}

// Print map values
void printMap(map<string, int> m) {
	map<string, int>::iterator iter;

	for(iter = m.begin(); iter!=m.end(); ++iter) {
		cout<<"Name: "<<iter->first<<" - Grade: "<<iter->second<<endl;
	}
}

// Search for a name in the map
void search(map<string, int> m, string s) {
	map<string, int>::iterator iter;
	map<string, int> results;

	cout<<"Searching for: "<<s<<endl;

	// Examples: n2 -> Found; n11 -> Not found
	for(iter = m.begin(); iter!=m.end(); ++iter) {
		if(iter->first.compare(s) == 0)
			results.insert(map<string, int>::value_type(iter->first, iter->second));
	}

	if(results.size() == 0)
		cout<<"Not found."<<endl;
	else
		printMap(results);
}


int main() {
	map<string, int> nameGrade;	// Map as <Name, Grade>
	string searchName;

	// Insert values in map
	cout<<endl<<"--- Insert values ---"<<endl;
	nameGrade = insertValues();

	// Print map values
	cout<<endl<<"--- Print values ---"<<endl;
	printMap(nameGrade);

	// Search for a name in the map
	cout<<endl<<"--- Search name ---"<<endl;
	cout<<"Write the name to search... ";
	cin>>searchName;
	search(nameGrade, searchName);

	return 0;
}
