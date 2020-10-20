#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    if(numRows < 2) return s;
    string res = "";
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < s.length(); j++){  // 画图找规律解答   
            if(j % (2*(numRows-1)) == i || j % (2*(numRows-1)) == (2*(numRows-1) - i) ){
                res += s[j];
            }
        }
//        cout<<i<<"   "<<res<<endl;
    }
    return res;

    }
};

//输入: s = "LEETCODEISHIRING", numRows = 3
//输出: "LCIRETOESIIGEDHN"
//
//
//输入: s = "LEETCODEISHIRING", numRows =?4
//输出:?"LDREOEIIECIHNTSG"

int main(){
	Solution sl;
//	string test = "dbbcbbd";
//	string test = "LEETCODEISHIRING";
	string test = "A";
	string test1 = "abcda";
	
//	int flag = issPalindrome(test1, 1, 3);
//	cout<<test<<" is 回文数？ "<<flag<<endl; 
	cout<<sl.convert(test, 1);
	
}