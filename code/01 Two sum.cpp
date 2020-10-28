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
	// sl.twoSum(test, target);

    int x[6]={2,4,6,8,5,7},*p=x,i;
    for(i=0; i<6; i++){
        printf("%2d", *(p++));
    }
    p=x;
    cout<<endl;
    for(i=0; i<6; i++){
        printf("%2d", *(p+i));
    }
    p=x;
    cout<<endl;
    for(i=0; i<6; i++){
        printf("%2d", *p++);
    }
    p=x;
    cout<<endl;
    for(i=0; i<6; i++){
        printf("%2d", (*p)++);
    }
	return 0;
}
