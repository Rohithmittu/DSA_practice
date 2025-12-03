#include <iostream>
using namespace std;

string solve(string s)
{

    int n = s.size();

    string temp = "", res = "";

    int maxlength = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        if (s[i] == ' ')
        {
            if (res.size() > maxlength)
            {
                maxlength = res.size();
                temp = res;
            }
            res = "";
        }
        else
        {
            res = res + s[i];
        }
       
    }

    return temp;
}

int main()
{

    string line;
    getline(cin, line);

    string ans = solve(line);

    cout << ans << endl;

    return 0;
}