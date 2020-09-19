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

class Solution {
public:

    // 动态规划
    int maxSubArray1(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        const int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));  
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            dp[i][i] = nums[i - 1];
        }
        int i = 1;
        for (int j = i; j <= n; j++) {
            if (j == 1) {
                dp[i][j] = dp[j][j];
                continue;
            }
            dp[i][j] = dp[i][j - 1] + dp[j][j];
            int tem1 = dp[j][j];
            dp[i][j] = dp[i][j] > tem1 ? dp[i][j] : tem1;
        }

        //cout << i << endl;
        int max = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dp[1][i] > max) max = dp[1][i];
        }
        return max;

    }
    struct MyStruct{
        int lmax=0;
        int rmax=0;
        int mmax=0;
        int sum=0;
        MyStruct(int lmax, int rmax, int mmax, int sum) : 
            lmax(lmax), rmax(rmax), mmax(mmax), sum(sum){}

    };
    MyStruct getRes(vector<int>& nums, int l, int r) {
        if (l == r) {
            //printf("return l=%d  r=%d \n", l, r);
            MyStruct ret =  MyStruct(nums[l], nums[l], nums[l], nums[l]);
            //print(ret);
            return ret;
        }
        int middle = (l + r) / 2;
        //printf("l=%d  r=%d \n", l, r);
        MyStruct lmax = getRes(nums, l, middle);
        MyStruct rmax = getRes(nums, middle + 1, r);
        int mmax = max(max(lmax.mmax, rmax.mmax), lmax.rmax + rmax.lmax);
        int lmaxValue = max(lmax.lmax, lmax.sum + rmax.lmax);
        int rmaxValue = max(rmax.rmax, rmax.sum + lmax.rmax);
        MyStruct ret = MyStruct(lmaxValue, rmaxValue, mmax, lmax.sum + rmax.sum );
    
        return ret;
    }
    void print(MyStruct sl) {
        printf("lmax=%d \nrmax=%d \nmmax=%d \nsum=%d\n", sl.lmax, sl.rmax, sl.mmax, sl.sum);
    }
    int maxSubArray(vector<int>& nums) {
        MyStruct res = getRes(nums, 0, nums.size() - 1);
        //print(res);
        return res.mmax;

    }
};
int main() {
    Solution sl;
    
    vector<int> test{ -2,1,-3,4,-1,2,1,-5,4 };
    int res;

    res = sl.maxSubArray(test) ;
    cout<<res;
    
   
  
}
