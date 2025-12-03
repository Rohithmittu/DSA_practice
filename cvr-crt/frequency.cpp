#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solve(vector<int>arr, int n)

{

    unordered_map<int, int> mp;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] == 1)
        {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    vector<int> ans = solve(arr, n);

    if(ans.size() == 0){
        cout << -1 << endl;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;

}




