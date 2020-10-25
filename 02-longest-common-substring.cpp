// longest common substring has iterative approach to solve.
// brute force 		--> time O(N^4) and O(1) space
// hashing technique	--> time O(N^2) and O(N^2) space
// dynamic programming 	--> time O(N^2) and O(N) space


#include<bits/stdc++.h>
using namespace std;

string longest_common_substring_brute(string s1, string s2){
	int s1_length = s1.size();
	int s2_length = s2.size();
	//creating dp table for string matching
	int dp[s1_length+1][s2_length+1] = {0};
	// using dp to get the longest chain
	for(int i = 1; i < s1_length+1; i++){
		for(int j = 1; j < s2_length+1; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
		}
	}
	// show dp
	for(int i = 0; i < s1_length + 1; i++){
		for(int j = 0; j < s2_length + 1; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	// get max number
	int max_number = INT_MIN;
	int x = 0;
	int y = 0;
	for(int i = 0; i < s1_length+1; i++){
		for(int j = 0; j < s2_length+1; j++){
			max_number = max(max_number,dp[i][j]);
		}
	}
	return s2.substr(max_number-s2.size(),max_number);
}

int main(){
	string s1 = "subsequence";
	string s2 = "que";
	cout << longest_common_substring_brute(s1,s2) << endl;
	return EXIT_SUCCESS;
}
