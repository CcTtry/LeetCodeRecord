class Solution {
public:
   
    string desPre(string str) {
        const int n = str.size();
        if (n == 1) {
            return string(string("1") + str[0]);
        }
        int count = 0;
        stack<char> temp;
        string res = "";
        for (int i = 0; i < n; i++) {
            if (temp.empty()) {
                temp.push(str[i]);
                count++;
            } else if (i == n - 1) {
                if (str[i] != temp.top()) {
                    res += std::to_string(count) + temp.top(); // 将结果添加到结果字符串中去
                    res += string(string("1") + str[i]);
                }
                else {
                    count++;
                    res += std::to_string(count) + temp.top(); // 将结果添加到结果字符串中去
                }
               
                while (!temp.empty()) {
                    temp.pop();
                }
                //cout << "n-1\n"<<res<<endl;
                return res;
            } else if (str[i] != temp.top()) {// 不为空，也和前一个字符不相等
                res += std::to_string(count) + temp.top(); // 将结果添加到结果字符串中去
                count = 0;  // 清零
                while (!temp.empty()) {
                    temp.pop();
                }
                temp.push(str[i]);
                count++;
            } else if (str[i] == temp.top() ) {
                temp.push(str[i]);
                count++;
            } else {
                printf("还有这种情况？？\n");
            }
        }
        return res;
    }
    string countAndSay(int n) {
        map<int, string> resMap;
        
        resMap.insert(make_pair(1, string("1")));
        resMap.insert(make_pair(2, string("11")));
        resMap.insert(make_pair(3, string("21")));
        string pre = resMap[1];
        //cout << "begin \n1  curstring is =   " << pre << endl;
        for (int i = 2; i <= n; i++) {
            string temp = desPre(pre);
            resMap[i] =  temp;
            //cout<<i << "   curstring is =   " << temp << endl;
            pre = temp;
        }
        return resMap[n];
    }

};