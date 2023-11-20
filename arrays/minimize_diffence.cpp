#include <bits/stdc++.h> 
int minimizeIt(vector<int> A, int K)
{

	sort(A.begin(),A.end());
	int res = abs((A[A.size()-1]-K)-(A[0]-K));
    for(int i=0; i<A.size()-1; i++) {
        int mini = min(A[0]+K, A[i+1]-K);
        int maxi = max(A[A.size()-1]-K, A[i]+K);
        if(mini<0 || maxi<0) {
            continue;
        }
        res = min(res,maxi-mini);
    }
    return res;
}