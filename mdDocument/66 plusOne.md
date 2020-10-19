<!-- TOC -->

- [66. 加一](#66-加一)
  - [题目描述](#题目描述)
  - [示例：](#示例)
  - [思路](#思路)
  - [源代码](#源代码)
  - [执行结果](#执行结果)
  - [简要分析](#简要分析)

<!-- /TOC -->
## 66. 加一
### 题目描述
>给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位， 数组中每个元素只存储单个数字 **(小于10的数字)** 。你可以假设除了整数 0 之外，这个整数不会以零开头。


### 示例：
示例 1:
```
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
```

示例 2:
```
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
```
<!-- -->
### 思路
本题可以将问题分析划分成两种情况：
    1. 数组需要扩展(数组的每一个元素都是9) -> 直接返回 首元素为1、其余元素均为0的元素。
    2. 数组不需要扩展。在元素$digits[size - 1]$上加1，做十进制的加1运算。
【<font color = red>强调部分</font>】
### 源代码
```C++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n = digits.size();
        int count9 = 0;
        for(int i=0; i<n; i++){
            if(digits[i] == 9) count9++;
        }
        if(count9 == n){
            vector<int> res(n+1, 0);
            res[0] = 1;
            return res;
        }

        int carry = 1;
        for(int i=n-1; i>=0; i--){
            if(digits[i] + carry == 10){
                carry = 1;
                digits[i] = 0;
                continue;
            }else{
                digits[i] += 1;
                break;
            }
        }
        return digits;
    }
};
```
### 执行结果
![](./images/66%20result_plusOne.png)
###  简要分析
