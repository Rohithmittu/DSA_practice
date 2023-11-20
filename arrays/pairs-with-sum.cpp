#include<bits/stdc++.h>
long long pairsWithGivenSum(int arr[], int n, int sum)
{

      unordered_map<int,int>mp;

   long long  int ans=0;

    for(int i=0;i<n;i++)

    {

        ans+=mp[sum-arr[i]];

        mp[arr[i]]++;

    }

    return ans;
}