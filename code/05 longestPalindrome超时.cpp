#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	int isPalindrome(string s, int begin, int end){
		int k;
		for(k = begin; k<=(begin+end)/2; k++){
			if(s[k] != s[end-(k-begin)]){
				return 0;
			}
		}
		return 1;
	}
    string longestPalindrome(string s) {
        int begin = 0, end = 0, maxLen = 0; // 用于记录最长子串的开始位置和结束位置
		int i = 0, j = 0, k = 0;
	
		for(i = 0; i < s.size(); i++) {
			for(j = i; j < s.size(); j++){
				int temp = 0, flag = 0;
				flag = isPalindrome(s, i, j);
				if(flag){
					if(j-i+1 > maxLen){
						begin = i;
						end = j;
						maxLen = (j - i + 1);
					}
				}				
			}
		}
		string res = "";
		for(k=begin; k<=end; k++){
			res += s[k];
			cout<<s[k]<<" ";
		}
		cout<<endl<<begin<<" "<<end<<" "<<(end - begin + 1);
    }
};

int issPalindrome(string s, int begin, int end){
	int k;
	for(k = begin; k<=(begin+end)/2; k++){
		if(s[k] != s[end-(k-begin)]){
			return 0;
		}
	}
	return 1;
}

int main(){
	Solution sl;
//	string test = "dbbcbbd";
	string test = "cbbd";
	string test1 ="babad";
	
//	int flag = issPalindrome(test1, 1, 3);
//	cout<<test<<" is 回文数？ "<<flag<<endl; 
	sl.longestPalindrome(test1);
	
}