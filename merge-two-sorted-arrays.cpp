#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){

	    // Write your code here.

    int first = 0,second = 0;

 

    int n = a.size();

    int m = b.size();

 

    while(first < n && second < m){

        if(a[first] < b[second]){

            first++;

        }else{

            a.insert(a.begin()+first,b[second]);

            first++;

            second++;

            n++;

        }

    }

    while(second<m){

        a.emplace_back(b[second]);

        second++;

    }

    b.clear();

}