public:

// Recursive function to calculate the minimum cost of word wrapping

    // int solveWordWrapRec(vector<int> &nums, int i, int j, int k) {
    
    //     // Base case: If there are no words to process, return 0 (no extra spaces)
    
    //     if (i > j) {
    
    //         return 0;
    
    //     }
    
     
    
    //     int ans = INT_MAX; // Initialize the answer to a large value
    
    //     int sum = 0; // Initialize the sum of word lengths
    
     
    
    //     // Iterate through words from index i to j
    
    //     for (int idx = i; idx <= j; idx++) {
    
    //         sum += nums[idx]; // Add the length of the current word to the sum
    
     
    
    //         // Case 1: If the current line is the last line
    
    //         if (sum <= k && idx == j) {
    
    //             return 0; // No extra spaces in the last line, return 0
    
    //         }
    
     
    
    //         // Case 2: If the current word can fit on the current line
    
    //         if (sum <= k) {
    
    //             int extraSpaces = (k - sum) * (k - sum); // Calculate extra spaces and its cost
    
    //             int cost = extraSpaces + solveWordWrapRec(nums, idx + 1, j, k); // Recursively calculate cost
    
    //             ans = min(ans, cost); // Update the answer with the minimum cost among all possible line breaks
    
    //             sum++; // Increment to handle space between words
    
    //         }
    
    //     }
    
     
    
    //     return ans;
    
    // }
    
    int solvemem(vector<int> &nums, int i, int j, int k,vector<vector<int>>&dp) {
    
        // Base case: If there are no words to process, return 0 (no extra spaces)
    
        if (i > j) {
    
            return 0;
    
        }
        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
    
     
    
        int ans = INT_MAX; // Initialize the answer to a large value
    
        int sum = 0; // Initialize the sum of word lengths
    
     
    
        // Iterate through words from index i to j
    
        for (int idx = i; idx <= j; idx++) {
    
            sum += nums[idx]; // Add the length of the current word to the sum
    
     
    
            // Case 1: If the current line is the last line
    
            if (sum <= k && idx == j) {
    
                return dp[i][j] = 0; // No extra spaces in the last line, return 0
    
            }
    
     
    
            // Case 2: If the current word can fit on the current line
    
            if (sum <= k ) {
    
                int extraSpaces = (k - sum) * (k - sum); // Calculate extra spaces and its cost
    
                int cost = extraSpaces + solvemem(nums, idx + 1, j, k,dp); // Recursively calculate cost
    
                ans = min(ans, cost); // Update the answer with the minimum cost among all possible line breaks
    
                sum++; // Increment to handle space between words
    
            }
    
        }
    
     
    
        return dp[i][j] = ans;
    
    }

 

    int solveWordWrap(vector<int>nums, int k) 

    { 

        int n = nums.size();

        // int cost = solveWordWrapRec(nums, 0, n - 1, k);

        // return cost;
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return solvemem(nums,0,n-1,k,dp);

    } 

};