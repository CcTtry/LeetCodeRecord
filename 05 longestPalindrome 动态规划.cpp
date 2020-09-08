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
		const int len = s.size();
		string res = "";
		if(len < 2){
			return s;
		}else if (len == 2){
            if(s[0] == s[1]) return s;
            else{
            	res += s[0] ;
                return res;
            }
        }
        // 以下为动态规划数组的初始化操作
		int dp[len][len];
		for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }
        for(int j = 0; j < len; j++){  // 初始化的时候，需要按列的顺序初始化 
        	for(int i = 0; i < j; i++){
        		if(s[i] != s[j]) dp[i][j] = 0;  //  首尾不相等，肯定不是回文数 
        		else{
        			if(j - i + 1 <= 2){
        				dp[i][j] = 1; 
					}
					else{
						dp[i][j] = dp[i+1][j-1];
					}	        		
				}
			}
		}


		int i = 0, j = 0, k = 0;
		for(i = 0; i < s.size(); i++) {
			for(j = i; j < s.size(); j++){
				int temp = 0, flag = 0;
				flag = dp[i][j];
				if(flag){
					if(j-i+1 > maxLen){
						begin = i;
						end = j;
						maxLen = (j - i + 1);
					}
				}				
			}
		}
		
		for(k=begin; k<=end; k++){
			res += s[k];
//			cout<<s[k]<<" ";
		}
        return res;
//		cout<<endl<<begin<<" "<<end<<" "<<(end - begin + 1);
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
	string test1 = "abcda";
	
//	int flag = issPalindrome(test1, 1, 3);
//	cout<<test<<" is 回文数？ "<<flag<<endl; 
	cout<<sl.longestPalindrome(test1);
	
}