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
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.insert(make_pair(nums[i], 0));
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (!res.count(i)) {
                return i;
            }
        }
        return nums.size() + 1;
    }
    
};

