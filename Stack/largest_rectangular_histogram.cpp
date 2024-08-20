//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> next(long long arr[], int n){
        vector<long long> next(n,-1);
        stack<int> s;
        s.push(-1);
        for (int i=n-1;i>=0;i--){
            while (s.size()!=1 and arr[s.top()]>=arr[i]){
                s.pop();
            }
            next[i]=s.top();
            s.push(i);
        }
        return next;
    } 
    vector<long long> prev(long long arr[], int n){
        vector<long long> prev(n,-1);
        stack<int> s;
        s.push(-1);
        for (int i=0;i<n;i++){
            while (s.size()!=1 and arr[s.top()]>=arr[i]){
                s.pop();
            }
            prev[i]=s.top();
            s.push(i);
        }
        return prev;
    }
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> right=next(arr,n);
        vector<long long> left=prev(arr,n);
        
        
     
        
        int area = -1;
        
        
        for (int i=0;i<n;i++){
            int l = arr[i];
            if(right[i] == -1){
                right[i] = n;
            }
            int  b = right[i] - left[i] -1;
            int newarea = l * b;
            area = max(area,newarea);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends