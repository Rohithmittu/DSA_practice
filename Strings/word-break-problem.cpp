int wordBreak(string A, vector<string> &B) {
       int i, j, n = B.size();

        //creating a set to store the words from the dictionary
        set<string> mp;
        for (i = 0; i < n; i++) {
            mp.insert(B[i]);
        }
        int len = (int)A.size();
        //creating a dynamic programming array, initialized as false
        vector<bool> dp(len + 1, false);
        dp[0] = true;

        //iterating through each character of the string
        for (int i = 1; i <= len; i++) {
            //iterating through the substrings of the string
            for (int j = i - 1; j >= 0; j--) {
                //checking if the substring is present in the dictionary
                if (dp[j] && mp.find(A.substr(j, i - j)) != mp.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        //returning the result
        return dp[len];
    }