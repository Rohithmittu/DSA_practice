#include <iostream>
using namespace std;

string solve(string s)
{

    int n = s.size();

    string ans = "";
    int i = 0;

    string temp = "";

    for (int i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            temp += s[i];
        }else{
            for(int i = 0;i<temp.size();i++){

            }
        }




    }
}

int main()
{

    string s;

    cin >> s;

    string ans = solve(s);

    cout << ans << endl;

    return 0;
}