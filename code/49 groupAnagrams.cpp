class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> mapRes;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mapRes[temp].push_back(strs[i]);
        }
        const int n = mapRes.size();
        map<string, vector<string>>::iterator iter;
        for (iter = mapRes.begin(); iter != mapRes.end(); iter++) {
            res.push_back(iter->second);
        }
        return res;
    }
};