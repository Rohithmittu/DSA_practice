//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // static int cmp(int a,int b)
    // {
    //     int count1 = __builtin_popcount(a);
    //     int count2 = __builtin_popcount(b);
    
    //     // this takes care of the stability of sorting algorithm too
    //     if (count1 <= count2)
    //         return false;
            
    //     return true;
    // }
       
    
    const int MAX_BITS = 32;
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            num &= (num - 1);
            count++;
        }
        return count;
    }
    
    void sortBySetBitCount(int arr[], int N) {
        
        // stable_sort(arr, arr+n, cmp);
        
        vector<vector<int>> count(MAX_BITS);
    
        for (int i = 0; i < N; ++i) {
            int setBits = countSetBits(arr[i]);
            count[setBits].push_back(arr[i]);
        }
    
        int index = 0;
        for (int i = 31; i >= 0; --i) {
            for (int j = 0; j < count[i].size(); ++j) {
                arr[index++] = count[i][j];
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends