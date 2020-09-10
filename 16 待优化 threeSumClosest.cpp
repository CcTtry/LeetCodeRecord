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
	int threeSumClosest(vector<int>& nums, int target) {
		vector <int> res;
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());
		 for(int i = 0; i < nums.size(); i++){
		 	printf(" %d  ", nums[i]);
		 }
		 printf("\n");
		int i, close_num=INT_MAX, abs_num = INT_MAX;
		for (i = 0;  i < nums.size() - 2; i++) {
			int  left = i + 1, right = nums.size() - 1;
			while(left < right){
				int tem = nums[i] + nums[left] + nums[right] - target;
				printf("\ncheck begin i=%d  nums[%d]=%d  left=%d nums[%d]=%d  right=%d  nums[%d]=%d\nclose_num=%d  tem=%d abd_num=%d\n\n\n", i, i, nums[i], left, left, nums[left], right, right, nums[right], close_num, tem, abs_num);
				tem = (tem > 0)?tem:(0-tem);
//				if(res.size() > 0) printf("out:   is [ %d +  %d +  %d ] = %d \n", res[0], res[1], res[2], (res[0] + res[1] + res[2])); 
				printf("\nbegin: \n[ %d , %d , %d ]\nclose_num=%d   tem=%d abs_num=%d", nums[i], nums[left], nums[right], close_num, tem, abs_num);
				if(tem < abs_num){
					close_num = nums[i] + nums[left] + nums[right];
					abs_num = tem;
					if (nums[i] + nums[left] + nums[right] - target < 0 && right > left) {
						left++;
//						printf("\nleft: [ %d , %d , %d ]\n", nums[i], nums[left], nums[right]);
					}
					else if (nums[i] + nums[left] + nums[right] - target > 0 && right > left) {
						right--;
//						printf("\nright: [ %d , %d , %d ]\n", nums[i], nums[left], nums[right]);
					}			
				}
				else if (nums[i] + nums[left] + nums[right] - target < 0 && right > left) {
					left++;
//					printf("\nout left: [ %d , %d , %d ]\n", nums[i], nums[left], nums[right]);
				}
				else if (nums[i] + nums[left] + nums[right] - target > 0 && right > left) {
					right--;
//					printf("\nout right: [ %d , %d , %d ]\n", nums[i], nums[left], nums[right]);
				}else{
					break;
				}
				printf("\ncheck end i=%d  nums[%d]=%d  left=%d nums[%d]=%d  right=%d  nums[%d]=%d\nclose_num=%d  tem=%d abd_num=%d\n\n\n", i, i, nums[i], left, left, nums[left], right, right, nums[right], close_num, tem, abs_num);
			}
		}
//		printf("result is [ %d +  %d +  %d ] = %d \n", res[0], res[1], res[2], (res[0] + res[1] + res[2]));
		
		return close_num;
	}
};


int main(){
	Solution sl;
	vector<int> nums {-1,2,2,23,444,89, 1,-4};
	vector<int> nums1 {0,0,0};
	vector<int> nums2 {1,1,1};
	vector<string> strs1 {"aca","cba"};
	int res;
	res = sl.threeSumClosest(nums, 3);
	cout<<res<<endl;
	
	return 0;
}