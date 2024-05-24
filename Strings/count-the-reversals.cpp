int countRev(string s)
{

    stack<char> st;

    if (s.length() % 2)
    {
        return -1;
    }

    int cnt = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '{')
            st.push(s[i]);
        else
        {
            if (st.empty())
            {
                cnt++;
                st.push('{');
            }
            else
                st.pop();
        }
    }

    cnt = cnt + (st.size() / 2);

    return cnt;
}