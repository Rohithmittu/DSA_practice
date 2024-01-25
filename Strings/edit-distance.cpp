 // int solve(string s, string t,int i,int j){
    //     int n = s.length();
    //     int m = t.length();
        
    //     if(i == n){
    //         return m - j;
    //     }
    //     if(j == m){
    //         return n - i;
    //     }
    //     int ans = 0;
    //     if(s[i] == t[j]){
    //         return solve(s,t,i+1,j+1);
            
    //     }else{
    //         int insert = 1 + solve(s,t,i+1,j);
    //         int delet =  1 +  solve(s,t,i,j+1);
    //         int replace = 1 + solve(s,t,i+1,j+1);
            
    //         ans = min(insert,min(delet,replace));
    //     }
        
    //     return ans;
    // }
    int solvemem(string s, string t,int i,int j,vector<vector<int>>&dp){
        int n = s.length();
        int m = t.length();
        
        if(i == n){
            return m - j;
        }
        if(j == m){
            return n - i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        if(s[i] == t[j]){
            return solvemem(s,t,i+1,j+1,dp);
            
        }else{
            int insert = 1 + solvemem(s,t,i+1,j,dp);
            int delet =  1 +  solvemem(s,t,i,j+1,dp);
            int replace = 1 + solvemem(s,t,i+1,j+1,dp);
            
            ans = min(insert,min(delet,replace));
        }
        
        return dp[i][j] = ans;
    }
    
  
    int editDistance(string s, string t) {
        
        // return solve(s,t,0,0);
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solvemem(s,t,0,0,dp);
        
        
        
    }