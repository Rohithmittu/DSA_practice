#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
int dy[] = {0, 1, 0, -1};

int solve(vector<vector<int>>& mat, int n, int x, int y,vector<vector<int>>&dp) {
    int max_len = 1; 

    if(dp[x][y] != -1){
        return dp[x][y];
    }

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n &&
            mat[nextX][nextY] == mat[x][y] + 1) {
            max_len = max(max_len, 1 + solve(mat, n, nextX, nextY,dp));
        }
    }

    return dp[x][y] = max_len;
}

int findLongestOverAll(vector<vector<int>>& mat, int n) {
    int max_path = 1;

    vector<vector<int>> dp(n,vector<int>(n,-1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_path = max(max_path, solve(mat, n, i, j,dp));
        }
    }

    return max_path;
}