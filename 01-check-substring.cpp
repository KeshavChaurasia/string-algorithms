// the problem is that we need to check if a given string s1 is a substring of another string s2
#include<bits/stdc++.h>
using namespace std;

int compute_hash(string s){
	const int p = 3;
	const int m = 1e9 + 9;
	long long hash = 0;
	long long pow = 1;
	for(char c: s){
		hash = (hash + (c - 'a' + 1) * pow ) % m;
		pow = ( pow * p ) % m;
	}
	return hash;
}

bool check_substring(const string s1, const string s2){
	int string1_length = s1.size();
	int string2_length = s2.size();
	int hash2 = compute_hash(s2);
	for(int i = 0; i < string1_length - string2_length ; i++){
		int hash1 = compute_hash(s1.substr(i,string2_length));
		if(hash1 == hash2) return true;
	}
	return false;
}	

int main(){
	string s1 = "abcdef";
	string s2 = "abc";
	cout << check_substring(s1,s2) << endl;
	return EXIT_SUCCESS;
}
