//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    
    bool isPoss(int arr[],int n,int m,int mid){
        int studenCount = 1;
        int pagesum = 0;
        
        for(int i = 0;i<n;i++){
            if(pagesum + arr[i] <= mid){
                pagesum = pagesum + arr[i];
            }else{
                studenCount++;
                if(studenCount > m || arr[i] > mid){
                    return false;
                }
                
                // pagesum = 0;
                // pagesum = pagesum + arr[i];
                
                pagesum = arr[i];
                
            }
        }
        
        return true;
    }
    
    
    long long findPages(int n, int arr[], int m) {
        int s = 0;
        int sum = 0;
        
        for(int i = 0;i<n;i++){
            sum = sum + arr[i];
        }
        
        int e = sum;
        
        int ans = -1;
        
        int mid = s + (e-s)/2;
        
        if(n<m){
            return -1;
        }
        
        while(s<=e){
            if(isPoss(arr,n,m,mid)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
                
            }
            
            mid =  s + (e-s)/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends