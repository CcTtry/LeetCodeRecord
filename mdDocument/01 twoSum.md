在一个数组中寻找相加和等于某个数的两个数
```C++
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j< nums.size(); j++){
                if (nums[i] + nums[j] == target){
                	cout<<"get it !    ";
               		cout<<i<<","<< j<<endl;
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main(){
	Solution sl;
	vector<int> test {2, 7, 11, 15};
	int target = 9;
	sl.twoSum(test, target);
	return 0;
}


```