//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool ispos(int n,int m,long long mid,int arr[]){
      int pc=1;
      
      long long sc = 0;
      
      for(int i = 0;i< n;i++){
          if(sc + arr[i] <= mid){
              sc += arr[i];
          }else{
              pc++;
              if(pc > m || arr[i] > mid){
                  return false;
              }
              sc = arr[i];
          }
          
      }
      
      return true;
  }
    long long minTime(int arr[], int n, int k)
    {
        long long s = 0;
        long long e = 0;
        
        for(int i = 0;i<n;i++){
            e += arr[i];
            
        }
        long long ans = -1;
        
        long long mid = s + (e-s)/2;
        
        while(s<=e){
            if(ispos(n,k,mid,arr)){
                ans = mid;
                e = mid -1;
            }else{
                s = mid+ 1;
            }
            
            mid = s + (e-s)/2;
            
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends