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
    int eleft = -1, eright = -1;
    int subSearch(vector<int>& nums, int begin, int end, int target) {
        if (begin > end) return -1;
        int middle = (begin + end) / 2, res = -1;
        if (nums[middle] == target)  return middle;
        else if (nums[end] == target) return end;
        else if (nums[begin] == target)  return begin;
        if (nums[middle] >= target && nums[begin] <= target) {
            res = subSearch(nums, begin, middle, target);
        }
        else if (nums[end] >= target && nums[middle] < target) {//注意循环控制条件
            res = subSearch(nums, (middle + 1 <= end) ? (middle + 1) : (end), end, target);
        }
        else {

            return -1;
        }
        if (res == -1) {
            eleft = begin;
            eright = end;
        }
        return res;
    }
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else {
                return (nums[0] > target) ? 0 : 1;
            }
        }
        const int N = nums.size();
        int tarIndex;
        tarIndex = subSearch(nums, 0, nums.size() - 1, target);
        if (tarIndex != -1) return tarIndex;
        else if (nums[0] > target) return 0;
        else if (nums[N - 1] < target) return N;
        // 以下为二分划定
        // printf("\nbegin eleft=%d, eright=%d\n\n", eleft, eright);
        if (nums[(eleft + eright) / 2] >= target && nums[eleft] <= target) {
            eright = (eleft + eright) / 2;
        }
        else if (nums[eright] >= target && nums[(eleft + eright) / 2 + 1] <= target) {
            eleft = (eleft + eright) / 2 + 1;
        }
        // printf("\nend eleft=%d, eright=%d\n\n", eleft, eright);
        for (int i = eleft; i < eright; i++) {
            if (nums[i]<target && nums[i + 1]>target) return i + 1;
        }
        cout << "错处" << endl;
        return 0;


    }
};
int main() {
    Solution sl;
   
    vector<int> test{ 4,5,6,7,0,1,2 };
    vector<int> test1{ 3, 1 };
    vector<int> test2{ 4,5,6,7,0,1,2 };
    vector<int> test3{ 1,2,8,7 };



    cout << sl.searchInsert(test3,8) << endl;
   
  
}

