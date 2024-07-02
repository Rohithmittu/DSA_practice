//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        // stack<char>st;
        // int n = S.size(),cnt=0;
        // for(int i=0;i<n;i++){
        //     if(S[i] == '['){
        //         st.push(S[i]);
        //     }
        //     else{
        //         if(!st.empty()){
        //             st.pop();
        //         }
        //         else{
        //             swap(S[i],S[i+1]);
        //             i--;
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        // TLE
    
        
         
        int ans =0, n= S.size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
          if(S[i]=='[')
          count++;
          else
          {
              count--;
              if(count<0)
              ans-=count;
          }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends