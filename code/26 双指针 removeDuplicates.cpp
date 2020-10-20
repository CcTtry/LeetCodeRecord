class Solution {
public:
    
    int removeDuplicates(vector<int>& nums) {//双指针解法
        if(nums.size() < 2){
            return int(nums.size());
        }
        int left = 0, right = 1;
        for(; right < nums.size(); ){
            if(nums[left] == nums[right]){
                right ++;
            }else{
                nums[left + 1] = nums[right];
                left ++;
            }
        }
        return left + 1;
    }

    
};