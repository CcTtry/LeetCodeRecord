#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map> 
#include <climits>
using namespace std;


class Solution {
public:
    int strToInt(string str) {
        int i = 0, flag = 1;
        int res = 0; //默认flag = 1，正数  先跳过 前面的字符串
        while (str[i] == ' ') i++;
        if (str[i] == '-') flag = -1;
        if (str[i] == '-' || str[i] == '+') i++;
        for (; i < str.size() && isdigit(str[i]); i++)  {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)) //溢出判定
                return flag == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (str[i] - '0');
        } 
        return flag * res;
    }
};

