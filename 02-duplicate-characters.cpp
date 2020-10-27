// print duplicate characters from string
//
#include<bits/stdc++.h>
using namespace std;

unordered_set<char> duplicate_characters(const string & s){
	unordered_set<char> table;
	unordered_set<char> duplicates;
	for(char c: s){
		if(table.find(c) != table.end()){
			duplicates.insert(c);
		}
		else {
			table.insert(c);
		}
	}
	return duplicates;
}

void print(const unordered_set<char> & table){
	for(char c: table){
		cout << c << endl;
	}
}	


int main(){
	string s =  "Keshav Chaurasia";
	unordered_set<char> results = duplicate_characters(s);	
	print(results);
	return EXIT_SUCCESS;
}
