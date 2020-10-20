class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() < 1){
            return int(nums.size());
        }
        if(nums.size() == 1){
            return nums[0]==val?0:1;
        }
        // sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        for(; right < nums.size(); right++){
            if(nums[right] != val){
                nums[left] = nums[right];
                left ++;
            }
        }
        return left + 1;
    }
};