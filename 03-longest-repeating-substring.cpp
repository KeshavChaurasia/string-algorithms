#include<bits/stdc++.h>
using namespace std;

void print(vector<string> & result){
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
	cout << endl;
}
void print(vector<int> & result){
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
}
vector<string> get_suffix_array(const string s){
	vector<string> output;
	int length = s.size();
	for(int i = 0 ; i < s.size(); i++){
		output.push_back(s.substr(length-1-i,i+1));
	}
	sort(output.begin(),output.end());
	// print(output);
	return output;
}

vector<int> get_longest_common_prefix(vector<string>& suffix_array){ 
	vector<int> result;
	result.push_back(0); // first element is undefined
	for(int i = 1; i < suffix_array.size(); i++){
		int count = 0;
		// cout << "matching " << suffix_array[i-1] << " and " << suffix_array[i] << endl;
		for(int j = 0; j < suffix_array[i-1].size(); j++){
			// cout << "matching " << suffix_array[i-1][j] << " and " << suffix_array[i][j] << endl;
			if(suffix_array[i-1][j] == suffix_array[i][j]){
				count++;
			}
		}
		result.push_back(count);
	}
	// print(result);
	return result;
}

string longest_repeating_substring(const string s){
	vector<string> suffix_array = get_suffix_array(s);
	vector<int> lcp = get_longest_common_prefix(suffix_array);
	int max_index = 0;
	int max_length = INT_MIN;
	for(int i = 0; i < lcp.size(); i++){
		if(lcp[i] > max_length){
			max_index = i;
			max_length = max(max_length,lcp[i]);
		}
	}
	cout << "Longest repeating string count is of " << max_length << " found at index " << max_index << endl;
	return suffix_array[max_index-1];
}	

int main(){
	string s = "banana";
	cout << longest_repeating_substring(s) << endl;
	return EXIT_SUCCESS;
}
