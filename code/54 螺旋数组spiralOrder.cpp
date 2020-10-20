class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int sum = m * n, count = 0;
        
        vector<vector<int>> flags(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                flags[i][j] = 0;
            }
        }

        int i = 0, j = 0;
        while (count < sum) {
            // right
            while (j < n && i < n && flags[i][j] != 1) {
                res.push_back(matrix[i][j]);
                count++;
                flags[i][j] = 1;
                j++;
            }
            //cout << i << " right " << j << endl;

            // down
            j = j - 1;
            i = i + 1;
            while (i < m && flags[i][j] != 1) {
                res.push_back(matrix[i][j]);
                count++;
                flags[i][j] = 1;
                i++;
            }
            //cout << i << " down " << j << endl;

            // left
            j = j - 1;
            i = i - 1;
            while (j >= 0 && flags[i][j] != 1) {
                res.push_back(matrix[i][j]);
                count++;
                flags[i][j] = 1;
                j--;
            }

            //cout << i << " left " << j << endl;

            // up
            i = i - 1;
            j = j + 1;
            while (i >= 0 && flags[i][j] != 1) {
                res.push_back(matrix[i][j]);
                count++;
                flags[i][j] = 1;
                i--;
            }

            //cout << i << " up " << j << endl;

            i = i + 1;
            j = j + 1;
            //cout << i << " " << j << endl;
        }
        return res;

    }

};