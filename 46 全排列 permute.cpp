class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    vector<int> visited;
    void initVisited(int n) {
        for (int i = 0; i < n; i++) {
            visited.push_back(0);
        }
    }
    void DFS(vector<int> nums, int index) {
        if (index == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 1) {
                continue;
            }
            visited[i] = 1;
            temp.push_back(nums[i]);
            DFS(nums, index + 1);
            visited[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return res;
        if (nums.size() == 1) {
            vector<int> temp{ nums[0] };
            res.push_back(temp);
            return res;
        }
        initVisited(nums.size());
        DFS(nums, 0);
        return res;
    }
};