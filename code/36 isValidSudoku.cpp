
// 使用三个数组存储 数独的合法条件

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
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        int rows[9][9] = { 0 };
        int cols[9][9] = { 0 };
        int boxs[9][9] = { 0 };

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int charNum = board[i][j] - '0' - 1;
                    if (rows[i][charNum] != 0) return false;
                    if (cols[j][charNum] != 0) return false;
                    if (boxs[i / 3 * 3 + j / 3][charNum] != 0) return false;
                    rows[i][charNum] = 1;
                    cols[j][charNum] = 1;
                    boxs[i / 3 * 3 + j / 3][charNum] = 1;
                }
            }
        }
        return true;
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
    vector<vector<int>> res;


    cout<<sl.isValidSudoku(board);
    
   
  
}