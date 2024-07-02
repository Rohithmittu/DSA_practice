//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
       string ans;
       unordered_map<string,int> hash;

    //adding all the strings in the array and calculating its frequency using map.
       for(int i=0;i<n;i++){
           hash[arr[i]]++;
       }
       
       int maxfreq=INT_MIN;

    //for calculating the string with the maximum frequency
       for(auto i:hash){
           if(i.second > maxfreq) maxfreq=i.second;
       }
       int secmaxfreq=INT_MIN;

        //for calculating the string with the second maximum frequency
       for(auto i: hash){
           if((i.second>secmaxfreq) && (i.second<maxfreq)){
             secmaxfreq=i.second;  
             ans=i.first;
           } 
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends