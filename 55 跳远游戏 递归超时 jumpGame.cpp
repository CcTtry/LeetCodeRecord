lass Solution {
public:
    string temp = "";
    vector<string> res;

    bool tag = false; 
    void dfsJump(vector<int>& nums, int cur, int index) {
        //index  表示后一个
        if (cur == nums.size() - 1) {
            res.push_back(temp);
            tag = true;

            return;
        }
        else if (cur > nums.size() - 1 || index == nums.size() - 1) {
            return;
        }

        for (int i = 1; i <= nums[cur]  && tag != true; i++) {
            //temp.push_back(num)
            temp.push_back(i + '0');
            dfsJump(nums, cur + i, index+1);
            temp.pop_back();
        }
        return;
    }
    bool canJump1(vector<int>& nums) {  // 递归方法超时
        if (nums.size()==0) return false;
        else if (nums.size() == 1) return true;
        dfsJump(nums, 0, 0);
        // for (int i = 0; i < res.size(); i++) {
        //     for (int j = 0; j < res[i].size(); j++) {
        //         cout << res[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return tag;
    }
    /*
        我们依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。对于当前遍历到的位置 xx，
        如果它在 最远可以到达的位置 的范围内，那么我们就可以从起点通过若干次跳跃到达该位置，
        因此我们可以用 x + \textit{nums}[x]x+nums[x] 更新 最远可以到达的位置。
        在遍历的过程中，如果 最远可以到达的位置 大于等于数组中的最后一个位置，那就说明最后一个位置可达,
        我们就可以直接返回 True 作为答案。反之，如果在遍历结束后，最后一个位置仍然不可达，我们就返回 False 作为答案。



    */
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int maxValue = nums[0];
        const int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (i <= maxValue) {
                maxValue = max(i + nums[i], maxValue);
            }
            if (maxValue >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};