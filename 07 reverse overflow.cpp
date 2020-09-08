#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int cal(int x){
        if(x == 0) return 1;
        long long  res = 1;
        for(int i = 1; i <= x; i++){
            res *= 10;
        }
        return res;
    }
    int reverse(int x){
        int count  = 0, nums = 1, temp = x;
        long long res = 0;
        long long array[32] = {0};
        while(temp){
            array[count] = (temp%10);
            temp /= 10;
            count ++;
        }
        for(int i = count -1; i >= 0; i--){
            res += array[i]*cal(count - i -1);
            
//            printf("array[%d] = %d  res = %d  addis = %d*%d =%d       ", i, array[i], res, cal(count - i -1), array[i], long(array[i]*cal(count - i -1)));
//            cout<< res<<endl;
        }
        

        return int(res);     
        
    }
    int reverse1(int x) {  // 注意溢出的判断
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }

};


int main(){
    Solution sl;
//  long long a =10000000000;
//  cout<<a<<endl;
//  string test = "dbbcbbd";
//  string test = "LEETCODEISHIRING";

    cout<<sl.reverse1(1534236469)<<endl;
}