class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int N = nums.size();
        int left = N -1 , right = N - 1, end = N - 1;
        for(int i = N - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                left = i;
                // cout<<"left =  "<<left<<endl;
                break;
            }
        }
        if (left == N - 1) {
            sort(nums.begin(), nums.end());
            // cout<<" 无解 "<<endl;
            return;
        }
        for (int i = N - 1; i >= left+1; i--) {
            if (nums[i] > nums[left]) {
                right = i;
                // cout<<"right is "<<right<<endl;
                break;
            }
        }
        // 交换left right的值，并将right之后的值全部反转
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        
        for (int i = left + 1, j = 0; i < N&&j<N &&i<N-j; i++, j++) {
            int temp = nums[i];
            nums[i] = nums[N - j -1];
            nums[N - j-1] = temp;
        }

    }
};