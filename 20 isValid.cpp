#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <stack>

#include <typeinfo>
#include <unordered_map>
using namespace std;
class Solution {
public:
	// 入栈出栈

	bool isValid(string s) {
		//char sign1l = '(', sign1r = ')', sign2l = '[', sign2r = ']', sign3l = '{', sign3r = '}';
		map<char, char> Match;
		Match['('] = ')';		Match[')'] = '(';
		Match['['] = ']';		Match[']'] = '[';
		Match['{'] = '}';		Match['}'] = '{';

		unordered_map<char, string> flagMap;  // 判断符号是左半边 还是 右半边 
		flagMap.insert(make_pair('(', "left"));	flagMap.insert(make_pair('[', "left"));	 flagMap.insert(make_pair('{', "left"));
		flagMap.insert(make_pair(')', "right"));flagMap.insert(make_pair(']', "right")); flagMap.insert(make_pair('}', "right"));
		
		if ((s.size() % 2 != 0)) {// 奇数违法 
			return false;
		}
		if ((s.size() == 0)) {
			return true;
		}
		stack<char> tem;
		// 输入的字符串 必须满足以下条件  ：下当前字符属于左半部分，则下一个字符不必须是 一个字符要么是当前字符的 
		for (int i = 0; i < s.size(); i++) {
			char tem1 = s[i];
			/*cout << tem1 << "   " << flagMap[tem1] << endl;
			cout << tem1 << "   " << (flagMap[tem1] == "left")<< endl;*/
			if (i == 0) { // 对第一个字符进行判断  首部必须为左符号 
				if (flagMap[s[0]] != "left") {
					return false;
				}
				else {
					tem.emplace(tem1);  //入栈
					continue;
				}
			}

			if (flagMap[tem1] == "left") { // 没有直接匹配 需要输入左符号
				tem.emplace(tem1);  //入栈
				//printf("\n%c 左符号入栈  matchflag is %c   \n", tem.top(), tem1);


			}
			else if (!tem.empty() && tem.top() == Match[tem1]) { // 直接匹配 
				//  printf("\n%c 直接匹配  matchflag is %c   \n", tem.top(), tem1);
				tem.pop();
				//  弹出两个匹配的字符 
			}

			else {
				/*printf("\ncurrent cahr  is %c   pre char = %c\n", tem1, tem.top());
				cout << flagMap[tem1] << endl;*/

				return false;
			}

		}
		if (tem.size() != 0) {
			return false;
		}
		return true;
	}
};
int main() {

	Solution sl;
	string t1 = "(]";
	string t2 = "{[]}([])[(";
	string t3 = "()[]{}";
	//	Line 1061: Char 9: runtime error: addition of unsigned offset to 0x7ffe8d2f3740 overflowed to 0x7ffe8d2f373f (basic_string.h)
	cout<<(sl.isValid(t3));
	//	print(reverse(p1));

	return 0;
}