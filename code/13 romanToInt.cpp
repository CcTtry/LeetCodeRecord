#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map> 
using namespace std;
class Solution {
public:
	int getValue(char c){
//		int a = c;
		switch(c){
			case 'I':
				return 1;
				break;
			case 'V':
				return 5;
				break;
			case 'X':
				return 10;
				break;
			case 'L':
				return 50;
				break;
			case 'C':
				return 100;
				break;
			case 'D':
				return 500;
				break;
			case 'M':
				return 1000;
				break;
			default:
				return -1;
		}
		return -1;
	}
    int romanToInt(string s){
    if(s.size() == 1) return getValue(s[0]);
	int sum = 0, pre_sum = 0, cur_sum = 0;  // 保存当前的值，前一个值
	pre_sum = getValue(s[0]);
//    cout<<pre_sum<<endl;
//	sum += pre_sum;
	for(int i = 1; i<s.size(); i++){
		cur_sum = getValue(s[i]);
		if(cur_sum > pre_sum){
			sum -= pre_sum;
		}
		else{
			sum += pre_sum;
		}
		pre_sum = cur_sum;		
	}
	sum += pre_sum;
	return sum;
	 
	
    }
};

int main(){
	Solution sl;
	string a = "III";
	string b = "MCMXCIV";
	string c = "IV";
	
	printf(" %d\n", sl.romanToInt(a));
	printf(" %d\n", sl.romanToInt(b));
	printf(" %d\n", sl.romanToInt(c));
//	printf("%d is ? %d\n", a, sl.isPalindrome(b));
//	printf("%d is ? %d\n", a, sl.isPalindrome(c));
//	printf("%d is ? %d\n", a, sl.isPalindrome(d));
}