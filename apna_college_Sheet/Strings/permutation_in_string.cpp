class Solution {
public:
    // bool issame(int freq1[], int freq2[]) {
    bool issame(vector<int> freq1,vector<int> freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

        // int freq[26] = {0};
        vector<int> freq(26,0);

        if(s1.size() > s2.size()){
            return false;
        }

        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }

        int s1len = s1.size();

        for (int i = 0; i <= s2.size() - s1len; i++) {

            int stindex = 0, idx = i;

            // int windfreq[26] = {0};
            vector<int> windfreq(26,0);

            while (stindex < s1len && idx < s2.size()) {

                windfreq[s2[idx] - 'a']++;
                stindex++;
                idx++;
            }

            if (issame(freq, windfreq)) {
                return true;
            }
        }

        return false;
    }
};