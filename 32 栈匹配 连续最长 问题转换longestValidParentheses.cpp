#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map> 
#include <unordered_map>
#include <stack>
#include <vector>
#include<set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0; //  关注题目中最长的包含有效括号的子串的长度。 注意如何表达“连续”这个特征
        int left = 0, right = 0, maxnum = 0, count = 0;   //count 存储临时的最大括号数目
        while (s[0] == ')') {
            s.erase(s.begin() + 0);
        }
        while (s.size() != 0 && s[s.size() - 1] == '(') {
            s.erase(s.begin() + s.size() - 1);
        }
        //cout << "处理之后的结果是" << s << endl;
        if (s.size() == 0) return 0;

        int i, j, lindex, rindex;
        const int N = s.size();
        vector<int> sign(N);
        /*for (int i = 0; i < N; i++) {
            sign[i] = -1;
            cout << sign[i] << "  ";
        }
        cout << endl;*/

        stack<char> value;
        stack<int>  index;  //两个数组，一个存储入栈的符号，一个存储入栈的下标   被匹配的字符sign[index]=1,将问题转化成求最连续1子串的问题
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                value.push(s[i]);
                index.push(i);
                sign[i] = 0;
            }
            else if (!value.empty() && s[i] == ')' && value.top() == '(') {  // 非空保证了i-1>=0
                //printf("\n匹配上了  前一个符号和弹出来的符号分别是 %c   %c\n",temp.top(), s[i]);
                value.pop();  // 如果匹配 就把栈里面的东西
                
                sign[i] = 1;
                sign[index.top()] = 1;
                index.pop();
                //if(!temp.empty()) printf("after： i=%d  j=%d   匹配上了  弹出来的符号是 %c   count=%d", i, j, temp.top(), count);

            }
           /* for (int i = 0; i < N; i++) {
                cout << sign[i] << "  ";
            }
            cout << "\n";*/

        }
        /*cout << "遍历之后的结果" << endl;
        for (int i = 0; i < N; i++) {
            cout << sign[i] << "  ";
        }
        cout << endl;*/
        for (int i = 0; i < N; i++) {
            if (sign[i] == 1) {
                count++;
                maxnum = (count > maxnum) ? count : maxnum;
            }
            else {
                count = 0;
            }
        }
        //cout << maxnum << endl;
        return maxnum;


    }
};
int main() {
    Solution sl;
    string ss = ")))((())(()))))(((";
    string ss1 = "()(()";
    string ss2= ")()())((((())))))";

    cout << sl.longestValidParentheses(ss1) << endl;
   
  
}



