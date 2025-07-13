#include <bits/stdc++.h>
using namespace std;

vector<int> findFrequency(string S) {
    map<char, int> mp;
    vector<int> ans;

    // Count frequency of each character in the string
    for (char c : S) {
        mp[c]++;
    }

    // Push frequency of each lowercase alphabet
    for (char c = 'a'; c <= 'z'; ++c) {
        ans.push_back(mp[c]); // will be 0 if not present
    }

    return ans;


    // vector<int>v(26,0);

    // for(char ch:S){

    //     v[ch-'a']++;

    // }

    // return v;
}
