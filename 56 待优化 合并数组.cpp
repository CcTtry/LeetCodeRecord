class Solution {
public:
    vector<vector<int>> res;
    bool ifMerge(vector<int>& a, vector<int>& b) {   // 能否合并
        vector<int> temp(2);
        temp[0] = min(a[0], b[0]);
        temp[1] = max(a[1], b[1]);
        if ((a[1] >= b[0] && a[1] <= b[1]) || b[1] >= a[0] && b[1] <= a[1]) {
            return true;  //相交合并
        }
        else if ((a[0] <= b[0] && a[1] >= b[1]) || (b[0] <= a[0] && b[1] >= a[1])) {
            return true;  //包含
        }
        return false;
    }

    vector<int> mergeTwo(vector<int>& a, vector<int>& b) {
        vector<int> temp(2);
        temp[0] = min(a[0], b[0]);
        temp[1] = max(a[1], b[1]);
        //printf("合并 [%d, %d]  和 [%d, %d] 合并成  [%d, %d]\n", a[0], a[1], b[0], b[1], temp[0], temp[1]);
        return temp;
    }
    bool cmp(const vector<int> &a, const vector<int> b) {
        return (a[0] < b[0]);
    }
    // O(n^2) 的算法复杂度  分治法
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return res;
        else if (intervals.size() == 1) {
            return intervals;
        }
        const int n = intervals.size();
        for (int i = 0; i < n; i++) {
            res.push_back(intervals[i]);
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size() - 1; i++) {
            for (int j = i + 1; j < res.size(); j++) {
                if (ifMerge(res[i], res[j])) {
                    vector<int> a = res[i];
                    vector<int> b = res[j];
                    res.erase(res.begin() + i);
                    res.erase(res.begin() + j-1);
                    res.insert(res.begin() + i, mergeTwo(a, b));
                    j = j - 1;
                }
                else {
                    continue;
                }
            }
        }
        return res;
    }


    //  先排序， 采用一个一个合并的方式进行操作
    
    ector<vector<int>> res;
    bool ifMerge(vector<int>& a, vector<int>& b) {   // 能否合并
        vector<int> temp(2);
        //printf("[%d, %d]  和 [%d, %d] 合并\n", a[0], a[1], b[0], b[1]);
        temp[0] = min(a[0], b[0]);
        temp[1] = max(a[1], b[1]);
        if ((a[1] >= b[0] && a[1] <= b[1]) || b[1] >= a[0] && b[1] <= a[1]) {
            //printf("[%d, %d]  和 [%d, %d] 合并成  [%d, %d]\n", a[0], a[1], b[0], b[1], temp[0], temp[1]);
            return true;  //相交合并
        }
        else if ((a[0] <= b[0] && a[1] >= b[1]) || (b[0] <= a[0] && b[1] >= a[1])) {
            //printf("[%d, %d]  和 [%d, %d] 合并成  [%d, %d]\n", a[0], a[1], b[0], b[1], temp[0], temp[1]);
            return true;
        }
        return false;
    }

    vector<int> mergeTwo(vector<int>& a, vector<int>& b) {
        vector<int> temp(2);
        //printf("[%d, %d]  和 [%d, %d] 合并\n", a[0], a[1], b[0], b[1]);
        temp[0] = min(a[0], b[0]);
        temp[1] = max(a[1], b[1]);
        //printf("合并 [%d, %d]  和 [%d, %d] 合并成  [%d, %d]\n", a[0], a[1], b[0], b[1], temp[0], temp[1]);
        return temp;
    }
    
    // O(n^2) 的算法复杂度  分治法
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return res;
        else if (intervals.size() == 1) {
            return intervals;
        }
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        int i = 0;
        for (int j = i + 1; j < intervals.size(); j++) {
            if (ifMerge(res[i], intervals[j])) {
                res[i][0] = min(res[i][0], intervals[j][0]);
                res[i][1] = max(res[i][1], intervals[j][1]);
            }
            else {
                i = i + 1;
                res.push_back(intervals[j]);
                continue;
            }
        }
        return res;
    }
};