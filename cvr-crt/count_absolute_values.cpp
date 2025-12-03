#include <iostream>
#include <set>
#include <vector>
using namespace std;

int solve(vector<int> arr, int n)
{

    int cnt = 0;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(abs(arr[i]));
    }
    return s.size();

    // sort(arr.begin(), arr.end());

    // for (int i = 0; i < n; i++)
    // {

    //     if (abs(arr[i]) != abs(arr[i + 1]))
    //     {

    //         cnt++;
    //     }
    // }

    // return cnt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    // int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = solve(arr, n);

    cout << ans << endl;

    return 0;
}