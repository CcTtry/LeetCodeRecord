#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <map> 
#include<climits>
using namespace std;


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector <int>> res;
		if (nums.size() < 3) return res;
		sort(nums.begin(), nums.end());
		int i;
		for (i = 0; nums[i] <= 0 && i < nums.size() - 2; i++) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) { // 避免重复元素 
				int  left = i + 1, right = nums.size() - 1, count = 0;
				while (left < right && nums[i] + nums[left] <= 0) {
					// printf("\nbegin: \n[ %d , %d , %d ]\n", nums[i], nums[left], nums[right]);
					if (nums[i] + nums[left] + nums[right] == 0) {
						// printf("\n\n\nget it !!!\n[ %d , %d , %d ] \n\n\n", nums[i], nums[left], nums[right]);
						vector<int> tem_res;
						tem_res.push_back(nums[i]);
						tem_res.push_back(nums[left]);
						tem_res.push_back(nums[right]);
						res.push_back(tem_res);
						//	同时移动左右指针
						while (left < right && nums[left + 1] == nums[left]) left++; // 跳过左侧相同的元素 
						left++;
						int tem_right = nums[right];
						while (right > left&& nums[right - 1] == nums[right]) right--;  // 跳过右侧相同的元素 
						right--;
					}
					else if (nums[i] + nums[left] + nums[right] < 0) {
						while (left < right && nums[left + 1] == nums[left]) left++; // 跳过左侧相同的元素 
						left++;

					}
					else if (nums[i] + nums[left] + nums[right] > 0) {
						int tem_right = nums[right];
						while (right > left&& nums[right - 1] == nums[right]) right--;  // 跳过右侧相同的元素 
						right--;
					}
				}

			}

		}
		return res;
	}
};



int main(){
	Solution sl;
	vector<int> nums {-1,0,0,0,1,4,10,2,-1,-4};
	vector<int> nums1 {0,0,0};
	vector<int> nums2 {1,1,1};
	vector<string> strs1 {"aca","cba"};
	vector<vector<int>>  res;
	res = sl.threeSum(nums);
	if (res.size()==0) {
		cout << "00000000000" << endl;
		return 0;
	}
//	res = sl.threeSum(nums1);
	cout<<"size is "<<res.size()<<endl;
	for(int i = 0; i<res.size(); i++){
		printf("[ %d , %d , %d ]", res[i][0], res[i][1], res[i][2]);
	}
//	cout<<sl.intToRoman(1994)<<endl;
	return 0;
}