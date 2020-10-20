#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
using namespace std;
class Solution {
    // 使用一个int 数组计算字符的个数 大于1 就归零
    // 遍历从第1个字符开始的无重复子串到 最后
public:
    int lengthOfLongestSubstring(string s){
        const int N = 256;
        int maxLen = 0, endj = 0;
        int counts[N] = {0};
        for(int i = 0; i<s.size(); i++){
            int tempMax = 0;
            
//          printf("nwaimian   i = %d and endj is %d \n", i, endj);
            for(int j=endj; j<s.size(); j++){
                
                counts[s[j]] += 1;
//                printf("j is %d   s[j]=%c  counts[%c]=%d\n maxlen is %d", j, s.at(j), s.at(j), counts[s.at(j)], maxLen);
                if(counts[s[j]] > 1){  // 已经出现过了的字符 
                    endj = j;
                    counts[s[j]] -= 1;
                    counts[s[i]] = 0;
//                  printf("i = %d and endj is %d \n\n", i, endj);
                    break;
                }else if(counts[s[j]] == 1){
                    tempMax = j - i + 1;
//                  printf("\nbefore  maxlen is %d  tempMax is %d\n",  maxLen, tempMax);
                    maxLen = (tempMax > maxLen)?tempMax:maxLen;
//                  printf("after  maxlen is %d  tempMax is %d \n\n\n",  maxLen, tempMax);
                }else{
                    cout<<"maybe some problems here "<<endl;
                }
            }
//            cout<<endl;
        }
        return maxLen;
    }
};

int main(){
    Solution sl;
    string test = "abcabcbb";
    string test1 = "pwwkew";
    string test2 = "bbbbb";
//  for(int i =0; i<test.size(); i++){
//      cout<<i<<" "<<test[i]<<endl;
//      cout<<i<<" "<<test.at(i)<<endl<<endl;
//  }
//  cout<<"the max len is "<<sl.lengthOfLongestSubstring(test)<<endl;
    cout<<"the max len is "<<sl.lengthOfLongestSubstring(test1)<<endl;
//  cout<<"the max len is "<<sl.lengthOfLongestSubstring(test2)<<endl;

    return 1;
}