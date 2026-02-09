class Solution {
public:
    bool issafe(vector<string>& temp, int row, int col, int n) {

        for (int i = 0; i < n; i++) {
            if (temp[row][i] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (temp[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (temp[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (temp[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& temp, int row,
               int n) {

        if (row == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (issafe(temp, row, i, n)) {
                temp[row][i] = 'Q';
                solve(ans, temp, row + 1, n);
                temp[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));

        solve(ans, temp, 0, n);

        return ans;
    }
};