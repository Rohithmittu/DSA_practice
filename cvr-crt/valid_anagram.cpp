#include <iostream>
using namespace std;

bool solve(string s1, string s2)
{

    // sort(s1.begin(), s1.end());
    // sort(s2.begin(), s2.end());

    // int n = s1.size();

    // int i = 0;

    // if (s1.size() != s2.size())
    // {
    //     return false;
    // }

    // while (i < n)
    // {
    //     if (s1[i] == s2[i])
    //     {
    //         i++;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    // return true;

    // O(nlogn)

    if (s1.size() != s2.size())
    {
        return false;
    }

    vector<int> charFrequency(26, 0);

    for (int i = 0; i < s1.size(); i++)
    {

        charFrequency[s1[i] - 'a']++;

        charFrequency[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (charFrequency[i] != 0)
        {
            return false;
        }
    }

    return true;

    // O(n);
}

int main()
{

    string s1;
    string s2;

    cin >> s1 >> s2;

    bool ans = solve(s1, s2);

    cout << ans << endl;
}
