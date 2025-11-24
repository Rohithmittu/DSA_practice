class Solution {
public:
    string longestPrefix(string s) {

        // int n = s.size();

        // vector<string> pre;
        // vector<string> suf;

        // string temp = "";


        // for (int i = 0; i < n - 1; i++) {
        //     temp += s[i];
        //     pre.push_back(temp);
        // }

        // for (int i = 1; i < n; i++) {
        //     suf.push_back(s.substr(i));
        // }

        // string ans = "";


        // for (string &p : pre) {
        //     for (string &q : suf) {
        //         if (p == q && p.size() > ans.size()) {
        //             ans = p;
        //         }
        //     }
        // }

        // return ans;

        int n = s.size();
        vector<int> lps(n);
        
        for (int i = 1, len = 0; i < n; i++) {
            while (len > 0 && s[i] != s[len])
                len = lps[len - 1];
            if (s[i] == s[len])
                lps[i] = ++len;
        }
        return s.substr(0, lps[n - 1]);


        // int n = s.size();
        // vector<int> lps(n, 0);f
        // int len = 0;  
        // int i = 1;

        // while (i < n) {
        //     if (s[i] == s[len]) {
        //         len++;
        //         lps[i] = len;
        //         i++;
        //     } else {
        //         if (len != 0) { 
        //             // fall back in the pattern
        //             len = lps[len - 1];  
        //         } else {
        //             lps[i] = 0;
        //             i++;
        //         }
        //     }
        // }

        // return s.substr(0, lps[n - 1]);
    }
};