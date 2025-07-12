// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// vector<int> countDistinctElements(const vector<int>& arr, int k) {
//     vector<int> ans;
//     set<int> myset;

//     for (int i = 0; i <= arr.size() - k; i++) {
//         myset.clear();
//         for (int j = i; j < i + k; j++)
//          {
//             myset.insert(arr[j]);
//         }
//         ans.push_back(myset.size());
//     }

//     return ans;
// }
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;

    vector<int> res;
    
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }

    res.push_back(mp.size());

    for (int i = k; i < n; i++)
    {

        if (mp[arr[i - k]] == 1)
        {

            mp.erase(arr[i - k]);
        }

        else
            mp[arr[i - k]]--;

        mp[arr[i]]++;

        res.push_back(mp.size());
    }

    return res;
}
int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = countDistinctElements(arr, k);

    cout << "Distinct counts: ";
    for (int x : result)

        cout << x << " ";
    cout << endl;

    return 0;
}
