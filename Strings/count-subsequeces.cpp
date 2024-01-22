// Function for generating the subsequences
    // void subsequences(string s, char op[], int i, int j,unordered_set<string> &sn)
    // {

    //     // Base Case
    //     if (s[i] == '\0') {
    //         op[j] = '\0';

    //         // Insert each generated
    //         // subsequence into the set
    //         sn.insert(op);
    //         return;
    //     }

    //     // Recursive Case
        
    //     // When a particular character is taken
    //     op[j] = s[i];
    //     subsequences(s, op, i + 1, j + 1,sn);

    //     // When a particular character isn't taken
    //     subsequences(s, op, i + 1, j,sn);
    //     return;
        
    // }

    int distinctSubsequences(string s)
    {
        // int m = s.size();

        // char op[m + 1];
        // unordered_set<string> sn;
        // subsequences(s, op, 0, 0,sn);

        // return sn.size()%1000000007;
        vector<int> last(26, -1); 

		int mod = 1e9 + 7;
	  
	    // Length of input string 
	    int n = s.size(); 
	  
	    // dp[i] is going to store count of distinct 
	    // subsequences of length i. 
	    long long dp[n + 1]; 
	  
	    // Empty substring has only one subsequence 
	    dp[0] = 1; 
	  
	    // Traverse through all lengths from 1 to n. 
	    for (int i = 1; i <= n; i++) { 
	        // Number of subsequences with substring 
	        // str[0..i-1] 
	        dp[i] = 2 * dp[i - 1]; 
	        
	        dp[i] %= mod;
	  
	        // If current character has appeared 
	        // before, then remove all subsequences 
	        // ending with previous occurrence. 
	        if (last[s[i - 1] - 'a'] != -1) 
	            dp[i] = (dp[i] - dp[last[s[i - 1] - 'a']] + mod)%mod; 
	  
	        // Mark occurrence of current character 
	        last[s[i - 1] - 'a'] = (i - 1); 
	    } 
	  
	    return (int)(dp[n]);
	}
    