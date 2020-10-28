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
        initVisited(nums.size());
        DFS(nums, 0);
        return res;
    }
};

int main() {
    Solution sl;
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
          {'8','.','.','.','6','.','.','.','3'},
          {'4','.','.','8','.','3','.','.','1'},
          {'7','.','.','.','2','.','.','.','6'},
          {'.','6','.','.','.','.','2','8','.'},
          {'.','.','.','4','1','9','.','.','5'},
          {'.','.','.','.','8','.','.','7','9'},
    };
    
    vector<int> test3{ 2, 3, 6, 7 };
    int  target = 7;
    vector<int> testt{ 1,2,3 };
    vector<vector<int>> res;



    res = sl.permute(testt) ;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
   
  
}

//cout << "\n\n\n\n\n\n\n 主函数打印\n";
//for (int i = 0; i < res.size(); i++) {
//    cout << "[ ";
//    for (int j = 0; j < res[i].size() - 1; j++) {
//        cout << res[i][j] << ", ";
//    }
//    cout << res[i][res[i].size() - 1] << " ]" << endl;
//
//}
//

//
//vector<int> test{ 4,5,6,7,0,1,2 };
//vector<int> test1{ 3, 1 };
//vector<int> test2{ 4,5,6,7,0,1,2 };