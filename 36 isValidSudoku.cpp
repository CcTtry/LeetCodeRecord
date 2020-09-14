
// 使用三个数组存储 数独的合法条件
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxs[9][9] = {0};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int charNum = board[i][j] - '0' - 1;
                    if(rows[i][charNum] != 0) return false;
                    if(cols[j][charNum] != 0) return false;
                    if(boxs[i/3*3 + j/3][charNum] != 0) return false;
                    rows[i][charNum] = 1;
                    cols[j][charNum] = 1;
                    boxs[i/3*3 + j/3][charNum] = 1;
                }
            }
        }
        return true;
    }
};