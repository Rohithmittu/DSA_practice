//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
      int kth(int *arr1, int *arr2, int *end1, int *end2, int k) 
    { 
        // Base cases: if one array is empty, return kth element from other array
        if (arr1 == end1) 
            return arr2[k]; 
        if (arr2 == end2) 
            return arr1[k]; 
        
        // Calculating the midpoints of the two arrays
        int mid1 = (end1 - arr1) / 2; 
        int mid2 = (end2 - arr2) / 2; 
        
        // If the sum of midpoints is less than k, exclude the elements before mid in the array with smaller mid
        if (mid1 + mid2 < k) 
        { 
            if (arr1[mid1] > arr2[mid2]) 
                return kth(arr1, arr2 + mid2 + 1, end1, end2, k - mid2 - 1); 
            else
                return kth(arr1 + mid1 + 1, arr2, end1, end2, k - mid1 - 1); 
        } 
        // If the sum of midpoints is greater than or equal to k, exclude the elements after mid in the array with larger mid
        else
        { 
            if (arr1[mid1] > arr2[mid2]) 
                return kth(arr1, arr2, arr1 + mid1, end2, k); 
            else
                return kth(arr1, arr2, end1, arr2 + mid2, k); 
        } 
    } 
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // int i = 0, j = 0;
        // int ans  = 0;

        // while (i < n && j < m) {
        //     if (k == 1) {
        //         return min(arr1[i], arr2[j]);
        //     }
    
        //     if (arr1[i] <= arr2[j]) {
        //         ans = arr1[i];
        //         i++;
        //     } else {
        //         ans = arr2[j];
        //         j++;
        //     }
        //     k--;
        // }
        
        // if (i < n) return arr1[i + k - 1];
        // else return arr2[j + k - 1];
        
        
         
         return kth(arr1, arr2, arr1+n, arr2+m, k-1);
    
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends