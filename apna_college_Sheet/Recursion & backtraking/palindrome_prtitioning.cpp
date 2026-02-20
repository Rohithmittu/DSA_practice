class Solution {
public:
    bool ispalin(string s) {
        string s2 = s;

        reverse(s2.begin(), s2.end());

        return s == s2;
    }

    void solve(string s, vector<string>& temp, vector<vector<string>>& ans) {

        if (s.size() == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {

            string sub = s.substr(0, i + 1);

            if (ispalin(sub)) {

                temp.push_back(sub);

                solve(s.substr(i + 1), temp, ans);

                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, temp, ans);

        return ans;
    }
};