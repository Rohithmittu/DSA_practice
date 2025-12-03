// elcomew
// lcomewe
// comewel

#include <iostream>
using namespace std;

// string solve(string s, int k)
// {

//     int n = s.size();

//     string ans = "";

//     for (int i = k; i < n; i++)
//     {

//         ans += s[i];
//     }

//     for (int i = 0; i < k; i++)
//     {
//         ans += s[i];
//     }

//     return ans;
// }

string solve(string s, int k)
{

    int n = s.size();

    string ans = "";

    for (int i = n - k; i < n; i++)
    {
        ans = ans + s[i];
    }

    for (int i = 0; i < n - k; i++)
    {
        ans = ans + s[i];
    }

    return ans;
}

int main()
{

    string s;
    int k;

    cin >> s;
    cin >> k;

    string ans = solve(s, k);

    cout << ans << endl;
    return 0;
}