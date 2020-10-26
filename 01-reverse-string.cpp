#include<bits/stdc++.h>
using namespace std;

void reverse_string(string & s){
	int left_ptr = 0;
	int right_ptr = s.size()-1;
	while(left_ptr < right_ptr){
		char c = s[left_ptr];
		s[left_ptr] = s[right_ptr];
		s[right_ptr] = c;
		left_ptr++;
		right_ptr--;
	}
}

int main(){
	string s = "keshav";
	cout << "original string " << s << endl;
	reverse_string(s);
	cout << "reverse string " << s << endl;
	return EXIT_SUCCESS;
}
