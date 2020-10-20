#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <map> 
#include <unordered_map>
#include <stack>
#include <vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void DFS(vector<int>& candidates, int begin, int target) {
        if (target < 0) {
            /* cout << "[ ";
             for (int j = 0; j < temp.size() - 1; j++) {
                 cout << temp[j] << ", ";
             }
             cout << temp[temp.size() - 1] << " ]" << endl;*/
            return;

        }    //不合法
        else if (target == 0) {
            /*printf("\n\n合法！");
            cout << "[ ";
            for (int j = 0; j < temp.size() - 1; j++) {
                cout << temp[j] << ", ";
            }
            cout << temp[temp.size() - 1] << " ]\n\n" << endl;*/
            res.push_back(temp);
            //temp.clear();

        }

        for (int i = begin; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            DFS(candidates, i, target - candidates[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        DFS(candidates, 0, target);
        return res;
    }
};



int main() {
    Solution sl;
    
    vector<int> test3{ 2, 3, 6, 7 };
    int  target = 7;
    vector<vector<int>> res;


    res = sl.combinationSum(test3, target);
    cout << "\n\n\n\n\n\n\n 主函数打印\n";
    for (int i = 0; i < res.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < res[i].size() -1; j++) {
            cout << res[i][j] << ", ";
        }
        cout << res[i][res[i].size() - 1] << " ]" << endl;

    }
   
  
}