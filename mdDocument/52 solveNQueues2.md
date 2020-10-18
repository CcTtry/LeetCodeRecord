```C++
```C++
class Solution {
public:
    vector<vector<string>> res;  // 保存最终的结果
    vector<string> flags;  //表示棋盘的摆放方式
    string temp = "";  
   
    void init(int n){  // 初始化棋盘的摆放
        for(int i=0; i<n; i++){
            temp.push_back('.');
        }
        for(int i=0; i<n; i++){
            flags.push_back(temp);
        }
    }
    bool isValid(int row, int col, int n, vector<string>& flags) {
        int count = 0;
        // 检查列
        for (int i = 0; i < row; i++) {
            if (flags[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 左对角线是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (flags[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 右对角线度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (flags[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void dfs(int row, int n, vector<string> &flags){ // 
        if(row == n){
            res.push_back(flags);
            return ;
        }

        for(int col=0; col<n; col++){
            if(isValid(row, col, n, flags)){
                flags[row][col] = 'Q';
                dfs(row+1, n, flags);
                flags[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        init(n);
        dfs(0, n, flags);
        return res;
    }
};
```

