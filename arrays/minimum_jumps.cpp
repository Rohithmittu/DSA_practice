#include <bits/stdc++.h> 

// int solve(vector<vector<int>> &arr, int row, int col, int n, int m) {
//     if (row == n - 1 && col == m - 1) {
//         return 0;  // base case: reached the destination
//     }

//     if (row >= n || col >= m) {
//         return INT_MAX;  // out-of-bounds, return a large value
//     }

//     int right = (col < m - 1) ? abs(arr[row][col] - arr[row][col + 1]) + solve(arr, row, col + 1, n, m) : INT_MAX;
//     int down = (row < n - 1) ? abs(arr[row][col] - arr[row + 1][col]) + solve(arr, row + 1, col, n, m) : INT_MAX;
//     int diagonal = (row < n - 1 && col < m - 1) ? abs(arr[row][col] - arr[row + 1][col + 1]) + solve(arr, row + 1, col + 1, n, m) : INT_MAX;

//     return min(right, min(down, diagonal));
// }
int solvemem(vector<vector<int>> &arr, int row, int col, int n, int m,vector<vector<int>> &dp) {
    if (row == n - 1 && col == m - 1) {
        return 0;  // base case: reached the destination
    }

    if (row >= n || col >= m) {
        return INT_MAX;  // out-of-bounds, return a large value
    }

    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    int right = (col < m - 1) ? abs(arr[row][col] - arr[row][col + 1]) + solvemem(arr, row, col + 1, n, m,dp) : INT_MAX;
    int down = (row < n - 1) ? abs(arr[row][col] - arr[row + 1][col]) + solvemem(arr, row + 1, col, n, m,dp) : INT_MAX;
    int diagonal = (row < n - 1 && col < m - 1) ? abs(arr[row][col] - arr[row + 1][col + 1]) + solvemem(arr, row + 1, col + 1, n, m,dp) : INT_MAX;

    return dp[row][col] = min(right, min(down, diagonal));
}

int findMinCost(vector<vector<int>> arr, int n, int m) {
    // return solve(arr, 0, 0, n, m);

    vector<vector<int>> dp(n,vector<int> (m,-1));

    return solvemem(arr,0,0,n,m,dp);
}