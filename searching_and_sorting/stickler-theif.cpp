int solve(int arr[],int n,int size){
        
        if(n == size){
            return 0;
        }
        
        if( n == size-1){
            return arr[n];
        }
        
        int incl = solve(arr,n+2,size) + arr[n];
        int excl = solve(arr,n+1,size) + 0;
        return max(incl,excl);
    }    
    int solvemem(int arr[],int n,int size,vector<int>&dp){
        
        if(n == size){
            return 0;
        }
        
        if( n == size-1){
            return arr[n];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int incl = solvemem(arr,n+2,size,dp) + arr[n];
        int excl = solvemem(arr,n+1,size,dp) + 0;
        dp[n] = max(incl,excl);
        return dp[n];
     }    

    int FindMaxSum(int arr[], int n)
    {
        // return solve(arr,0,n);
        
        vector<int>dp(n,-1);
        return solvemem(arr,0,n,dp);
        
    }