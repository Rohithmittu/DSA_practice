//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // if(C==0){
        //     return A==B;
        // }
        // else if((B-A)%C==0 & (B-A)/C >=0){
        //     return 1;
        // }
        // else{
        //     return 0;
        // }
        
        
        int d = (B - A);
        
        // If the difference is 0, A and B are in sequence
        if(d == 0)
            return 1;
        
        // If the difference is negative
        if(d < 0){
            // If C is positive, A and B can't be in sequence
            if(C >= 0)
                return 0;
            
            // If C is a divisor of the difference, A and B are in sequence
            if(d%C == 0)
                return 1;
            
            // A and B are not in sequence
            return 0;
        }
        // If the difference is positive
        else{
            // If C is negative, A and B can't be in sequence
            if(C <= 0)
                return 0;
            
            // If C is a divisor of the difference, A and B are in sequence
            if(d%C == 0)
                return 1;
            
            // A and B are not in sequence
            return 0;
        }
        
        // Default case, A and B are not in sequence
        return 0;
    }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends