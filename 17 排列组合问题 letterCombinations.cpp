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
	string cur_str = "";   // 深度优先遍历一课树， 每到达一次叶子结点，都输出一次cur_str字符串 
	vector<string> res;    // 
	map<char, string> phoneMap = {
        		{'2', "abc"}, {'3', "def"}, 
				{'4', "ghi"}, {'5', "jkl"}, 
				{'6', "mno"}, {'7', "pqrs"},
			    {'8', "tuv"}, {'9', "wxyz"}
   	};
	void DFS(int index, string digits){ // 数字的下标  输入的字符串的长度     （输入一个数字串，此处的下标表示的是第index个数字  
		if(index == digits.size()){
			res.push_back(cur_str);
			return ;
		}
		char pos = digits[index];  // 对应位置的数字 的ASCII码 
		for(int i = 0; i < phoneMap[pos].size(); i++ ) {//遍历每一个数字所有的选择 
			cur_str.push_back(phoneMap[pos][i]);
			DFS(index+1, digits);
			cur_str.pop_back();
		}
	}
    vector<string> letterCombinations(string digits) {
    	
    	if(digits.size() == 0) return res;
		DFS(0, digits);

    	return res;


    }
};

int main(){
	string test = "23";
	std::vector<string> v;
	Solution sl;
	v = sl.letterCombinations(test);
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	string test2 = "233";
//	std::vector<string> v;
//	Solution sl;
	v = sl.letterCombinations(test2);
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<" ";
	}

	return 0;
}