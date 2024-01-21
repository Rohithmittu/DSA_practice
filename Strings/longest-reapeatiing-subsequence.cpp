	public:
	
	   // int solve(int i,int j,string &txt,string &str){
	        
	   //     if(i < 0 || j < 0){
	   //         return 0;
	   //     }
	        
	   //     if(str[i] == txt[j] && i != j){
	   //         return 1 + solve(i-1,j-1,txt,str);
	   //     }
	        
	   //     return max(solve(i,j-1,txt,str),solve(i-1,j,txt,str));
	        
	   // }
	   // int solvemem(int i,int j,string &txt,string &str,vector<vector<int>>&dp){
	        
	   //     if(i < 0 || j < 0){
	   //         return 0;
	   //     }
	        
	   //     if(dp[i][j] != -1){
	   //         return dp[i][j];
	   //     }
	        
	   //     if(str[i] == txt[j] && i != j){
	   //         return dp[i][j] = 1 + solvemem(i-1,j-1,txt,str,dp);
	   //     }
	        
	   //     return dp[i][j] = max(solvemem(i,j-1,txt,str,dp),solvemem(i-1,j,txt,str,dp));
	        
	   // }
	
	    
	    
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
		    string txt(str.begin(),str.end());
		  //  return solve(n-1,n-1,txt,str);
		  //vector<vector<int>>dp(n,vector<int>(n,-1));
		  //return solvemem(n-1,n-1,txt,str,dp);
		  vector<vector<int>>dp(n+1,vector<int>(n+1));
		  for(int i = 1;i<=n;i++){
		      for(int j = 1;j<= n;j++){
		          if(str[i-1] == txt[j-1] && i != j){
		              dp[i][j] = 1 + dp[i-1][j-1];
		          }
		          else{
		              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		          }
		      }
		  }
		  return dp[n][n];
		}