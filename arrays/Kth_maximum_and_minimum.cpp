#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)

{

    sort(arr.begin(),arr.end());

    int a=-1,b=-1;

    for(int i=0;i<n;i++){

        if(i==k-1){

            a = arr[i];

        }

        if(i==n-k){

            b=arr[i];

        }

    }

    return {a,b};

}