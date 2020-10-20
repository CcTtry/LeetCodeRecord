#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector <int>> res;
            if (nums.size() < 4) return res;
            sort(nums.begin(), nums.end());
            for(int k = 0; k<nums.size() - 3; k++) {
                if(k>0 && nums[k] == nums[k-1]) {
                    continue;
                }
                int max1 = nums[k] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
                if(max1 < target) {
                    continue;
                }
                for (int i = k + 1;  i < nums.size() - 2; i++) {
                    if(i > k+1 && nums[i] == nums[i-1]) {//注意i指针是根据k来设置的 
                        continue;
                    }
                    // 避免重复元素
//                  int min1=nums[i]+nums[i+1]+nums[i+2];
//                  if(min1>target1) {
//                      break;
//                  }
                    /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略*/
//                  int max1=nums[i] + nums[nums.size()-1]+nums[nums.size()-2];
//                  if(max1<target1) {
//                      continue;
//                  }
                    
                    int  left = i + 1, right = nums.size() - 1;
//                  printf("\n\n\nout is k=%d   i=%d  left=%d  right=%d\n", k, i, left, right);
                    while (left < right) { // && nums[k] + nums[i] + nums[left] <= target
//                      printf("\n\n\nk=%d   i=%d  left=%d  right=%d\n", k, i, left, right);
//                      printf("nums[%d]=%d  nums[%d]=%d  nums[%d]=%d  nums[%d]=%d\n", nums[k], nums[i], nums[left], nums[right]);
                        if (nums[k] + nums[i] + nums[left] + nums[right] == target) {
                            cout<<"get it !!!!!!"<<endl;
                            vector<int> tem_res;
                            tem_res.push_back(nums[k]);
                            tem_res.push_back(nums[i]);
                            tem_res.push_back(nums[left]);
                            tem_res.push_back(nums[right]);
                            res.push_back(tem_res);
                            tem_res.clear();

                            //  同时移动左右指针
                            while (left < right && nums[left + 1] == nums[left]) left++; // 跳过左侧相同的元素
                            left++;
                            int tem_right = nums[right];
                            while (right > left&& nums[right - 1] == nums[right]) right--;  // 跳过右侧相同的元素
                            right--;
                        } else if (nums[k] + nums[i] + nums[left] + nums[right] < target) {
                            while (left < right && nums[left + 1] == nums[left]) left++;
                            left++;
                        } else if (nums[k] + nums[i] + nums[left] + nums[right] > target) {
                            while (right > left && nums[right - 1] == nums[right]) right--;
                            right--;
                        }
                    }
                }
            }

            return res;
        }
};

int main() {
    vector<vector<int>> res;
    std::vector<int> value {1, 0, -1, 0, -2, 2} ;
    std::vector<int> value1 {0, 0, 0,0} ;
    Solution sl;
    res = sl.fourSum(value1, 0);
    for(int j = 0; j<value1.size(); j++){
            cout<<value1[j]<<" ";
    }
    cout<<endl;
//  value = sl.letterCombinations(test2);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"endl;";

    return 0;
}