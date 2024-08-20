//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int checkRedundancy(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '*' || ch == '+' || ch == '-' || ch == '/')
            {
                st.push(s[i]);
            }
            else
            {
                if (s[i] == ')')
                {
                    bool isredundent = true;
                    while (st.top() != '(')
                    {
                        char top = st.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/')
                        {
                            isredundent = false;
                        }
                        st.pop();
                    }

                    if (isredundent == true)
                    {
                        return true;
                    }

                    st.pop();
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    }
}

// } Driver Code Ends