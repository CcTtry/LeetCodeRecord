#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <map> 
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() == 0) return "";
        int maxLen = INT_MIN, minLen = INT_MAX, num = 0, i, j;   // num用来保存相同的字符个数
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() > maxLen) maxLen = strs[i].size();
            if(strs[i].size() < minLen) minLen = strs[i].size();
        }
        const int len = minLen;
        for(i = 0; i < minLen; i++){
            for(j = 0; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                	return strs[0].substr(0, num);
                }
                if(j == strs.size() - 1){
                    num += 1;
               	}
                

            }
        } 
//        cout<<"num is "<<num<<endl;
        if(num == 0) return "";
//        cout<<"num is "<<num<<endl;

        return strs[0].substr(0, num);
    }
};


int main() {
	Solution sl;
	vector<string> strs {"flower","flow","flight"};
	vector<string> strs1 {"aca","cba"};
	cout<<sl.longestCommonPrefix(strs1)<<endl;
//	cout<<sl.intToRoman(1994)<<endl;
	return 0;
}