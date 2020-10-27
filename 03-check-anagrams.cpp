// check if two strings are anagram to each other
// By the way, two String is called anagram, if they contains the same characters but on different order 
// e.g. army and mary, stop and pots, etc. Anagrams are actually a mix-up of characters in String. 
// 
// One method is to sort both strings and then check if the string is equal or not
// but this method replaces original string and may not be the case given by the

#include<bits/stdc++.h>
using namespace std;


bool check_anagram(const string & s1, const string & s2){
	// anagram strings should have same size
	if(s1.size() != s2.size()) return false;
	// creating char frequency table for both string to compare the character counts in each string.
	// if equal then both strings are anagram to each other
	unordered_map<char,int> s1_table, s2_table;
	for(char c: s1){
		if(s1_table.find(c) != s1_table.end()){
			s1_table[c]++;
		}
		else {
			s1_table[c] = 1;
		}
	}
	for(char c: s2){
		if(s2_table.find(c) != s2_table.end()){
			s2_table[c]++;
		}
		else {
			s2_table[c] = 1;
		}
	}
	// let's compare if the hash map is equal or not
	for(auto k: s1_table){
		// if the character in string 1 doesn't exist in string 2 then return false
		if(s2_table.find(k.first) == s2_table.end()){
			return false;
		}
		// if character found but frequency doesn't match then return false 
		else if (k.second != s2_table[k.first]){
			return false;
		}	
	}
	return true;
}

int main(){
	string s1 = "keshav", s2="vashek";
	cout << check_anagram(s1,s2) << endl;
	return EXIT_SUCCESS;
}
