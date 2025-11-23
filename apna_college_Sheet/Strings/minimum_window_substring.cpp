class Solution {
public:
    string minWindow(string s, string t) {

        // int n = s.size();
        // int m = t.size();

        // int minl = INT_MAX, st = -1;

        // for (int i = 0; i < n; i++) {

        //     int hash[256] = {0};
        //     int cnt = 0;

        //     for (int j = 0; j < m; j++) {
        //         hash[t[j]]++;
        //     }

        //     for (int j = i; j < n; j++) {
        //         if (hash[s[j]] > 0) {
        //             cnt++;
        //         }

        //         hash[s[j]]--;

        //         if (cnt == m) {

        //             if (j - i + 1 < minl) {
        //                 minl = j - i + 1;
        //                 st = i;
        //             }

        //             break;
        //         }
        //     }
        // }

        // if (st == -1) {
        //     return "";
        // }

        // return s.substr(st, minl);

        int n = s.size();
        int m = t.size();

        int left = 0, right = 0;

        int minl = INT_MAX, st = -1, cnt = 0;

        int hash[256] = {0};

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (right < n) {

            // expand window
            if (hash[s[right]] > 0)
                cnt++;

            hash[s[right]]--;
            right++;

            // try to shrink window
            while (cnt == m) {

                if (right - left < minl) {
                    minl = right - left;
                    st = left;
                }

                // bring back char to hash when removing from left
                hash[s[left]]++;

                // if this char was required, we break validity
                if (hash[s[left]] > 0)
                    cnt--;

                left++;
            }
        }

        if (st == -1) {
            return "";
        }

        return s.substr(st, minl);
    }
};