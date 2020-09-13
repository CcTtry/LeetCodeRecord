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
    // 题解思路  先测试得到旋转的位置，然后根据旋转的位置，然后执行二分查找  其中找到旋转的位置散发复杂度为）O(logn)  二分查找的算法复杂度也为O(logn)  
    // 算法复杂度总共为 2*O(logn)
    int min_index = 0;

    void findMin(vector<int>& nums, int begin, int end) {
        int middle = (begin + end) / 2;
        // printf("begin=%d   end=%d  middle=%d\n", begin, end, middle);
        if (begin >= end) {
            return;
        }
        else if (end - begin == 1) {
            if (nums[begin] > nums[end]) {
                min_index = end;
                
            }
            return;
        }
        else if (end - begin == 2) {
            if (nums[begin] > nums[begin + 1]) {
                min_index = begin + 1;
                
            }
            else if (nums[begin + 1] > nums[end]) {
                min_index = end;
                //return;
            }
            return;
        }

        if (nums[middle] < nums[middle - 1]) {
            min_index = middle;
            return;
        }
        else if (nums[middle] > nums[middle + 1]) {
            min_index = middle + 1;
            return;
        }
        //printf("next  begin=%d   end=%d  middle=%d\n", begin, end, middle);
        findMin(nums, begin, middle);
        findMin(nums, middle + 1, end);
        return;

    }
    int subSearch(vector<int>& nums, int begin, int end, int target) {
        int res = -1;
        if (begin > end) return -1;
        int middle = (begin + end) / 2;
        if (nums[middle] == target)  return middle;
        else if (nums[end] == target) return end;
        else if (nums[begin] == target)  return begin;

        if(nums[middle] >= target && nums[begin]<=target) {
            /*printf("begin-middle:  begin=%d, end=%d\n", begin, middle);
            for (int i = 0; i <= middle; i++) {
                printf("nums[%d]=%d   ", i, nums[i]);
            }
            cout << endl;*/

            res = subSearch(nums, begin, middle, target);
        }
        else if (nums[end] >= target && nums[middle+1]<=target) {
           /* printf("middle-end:  begin=%d, end=%d\n", middle, end);
            for (int i = middle + 1; i < end; i++) {
                printf("nums[%d]=%d   ", i, nums[i]);
            }
            cout << endl;*/
            res = subSearch(nums, middle + 1, end, target);
        }
        else {
            // 无解
            //cout << "无解\n";
            return -1;
        }
        return res;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        else if (nums.size() <= 3) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }
        
        const int N = nums.size();
        findMin(nums, 0, N - 1);
        for (int i = 0; i < N; i++) {
            printf("nums[%d]=%d   ", i, nums[i]);
        }

        printf("\nMinIndex is %d\n\n", min_index);
        int resIndex = -1;
        if (min_index == 0) {
            resIndex = subSearch(nums, 0, N - 1, target);
        }
        else {
            if (nums[N - 1] >= target) {
                //cout << " 后半部分  " << min_index << endl;
                resIndex = subSearch(nums, min_index, N - 1, target);
            }
            else if (nums[min_index - 1] >= target) {
                //cout << " 前半部分   " <<min_index<< endl;
                resIndex = subSearch(nums, 0, min_index-1, target);
            }
        }
        for (int i = 0; i < N; i++){
            printf("nums[%d]=%d   ", i, nums[i]);
        }

        printf("\nMinIndex is %d\n\n", min_index);
        printf("\ntargetIndex is %d\n\n", resIndex);
        return resIndex;
    }
};
int main() {
    Solution sl;
    string ss = ")))((())(()))))(((";
    string ss1 = "()(()";
    string ss2= ")()())((((())))))";
    vector<int> test{ 4,5,6,7,0,1,2 };
    vector<int> test1{ 3, 1 };
    vector<int> test2{ 4,5,6,7,0,1,2 };

    cout << sl.search(test2,6) << endl;
   
  
}

