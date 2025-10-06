class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // int n = s.size();
        // int maxL = 0;

        // for (int i = 0; i < n; i++) {

        //     int hash[256] = {0};

        //     for (int j = i; j < n; j++) {

        //         if (hash[s[j]] == 1) {
        //             break;
        //         }

        //         hash[s[j]] = 1;

        //         int len = j - i + 1;

        //         maxL = max(len, maxL);
        //     }
        // }

        // return maxL;
        // O(n^2)

        int n = s.size();
        int l = 0, r = 0, maxlen = 0;

        // int hash[256] = {-1}; 
        vector<int> hash(256, -1);

        while (r < n) {

            
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            hash[s[r]] = r;
            r++;
        }

        return maxlen;

        // O(n)
    }
};