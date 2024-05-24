public:
/*You are required to complete below method */
//  long long int Solve(string str, int i, int j) {
//     if (i == j) // Base case: when the indices are the same, there is one palindrome
//         return 1;

//     if (i > j) // Base case: when the first index is greater than the second, there are no palindromes
//         return 0;

//     if (str[i] == str[j]) {
//         // If the characters at indices i and j are the same, we can form palindromic subsequences
//         // by including or excluding both characters, so we add 1 and make recursive calls.
//         return (1 + Solve(str, i + 1, j)%mod + Solve(str, i, j - 1)%mod)%mod;
//     } else {
//         // If the characters at indices i and j are different, we exclude one of them and make recursive calls.
//         return (Solve(str, i + 1, j)%mod + Solve(str, i, j - 1)%mod - Solve(str, i + 1, j - 1)%mod)%mod;
//     }
// }

int mod = 1e9 + 7;

long long int Solve(string &str, int i, int j, vector<vector<int>> &dp)
{
    if (i == j) // Base case: when the indices are the same, there is one palindrome
        return 1;

    if (i > j) // Base case: when the first index is greater than the second, there are no palindromes
        return 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (str[i] == str[j])
    {
        // If the characters at indices i and j are the same, we can form palindromic subsequences
        // by including or excluding both characters, so we add 1 and make recursive calls.
        return dp[i][j] = (1 + Solve(str, i + 1, j, dp) % mod + Solve(str, i, j - 1, dp) % mod) % mod;
    }
    else
    {
        // If the characters at indices i and j are different, we exclude one of them and make recursive calls.
        return dp[i][j] = (Solve(str, i + 1, j, dp) % mod + Solve(str, i, j - 1, dp) % mod - Solve(str, i + 1, j - 1, dp) % mod) % mod;
    }
}

public:
/*You are required to  complete below method */
long long int countPS(string str)
{
    // Your code here
    //   return Solve(str,0,str.size()-1);
    vector<vector<int>> dp(str.size(), vector<int>(str.size(), -1));
    return (Solve(str, 0, str.size() - 1, dp) + mod) % mod;
}
