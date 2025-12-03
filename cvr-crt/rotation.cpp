// elcomew
// lcomewe
// comewel

#include <iostream>
using namespace std;

bool solve(string s1, string s2)
{

    int n1 = s1.size();
    int n2 = s2.size();

    s1 = s1 + s2;

    if (n1 != n2)
    {
        return false;
    }

    if (s1.find(s2) < s1.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string s1, s2;

    cin >> s1 >> s2;

    bool ans = solve(s1, s2);

    cout << ans << endl;

    return 0;
}