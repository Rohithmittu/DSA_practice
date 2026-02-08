#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> arr)
{

    int n = arr.size();

    vector<int> ans(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {

        ans[i] = arr[i % n];
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

    vector<int> ans = solve(arr);

    for (int i = 0; i < 2 * n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}