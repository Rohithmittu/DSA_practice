class Solution {
public:
    bool isAnagram(string s, string t) {

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // int n = s.size();

        // int i = 0;

        // if (s.size() != t.size()) {
        //     return false;
        // }

        // while (i < n) {
        //     if (s[i] == t[i]) {
        //         i++;
        //     } else {
        //         return false;
        //     }
        // }

        // return true;


        if (s.size() != t.size()) {
            return false;
        }
      

        vector<int> charFrequency(26, 0);
      

        for (int i = 0; i < s.size(); ++i) {

            charFrequency[s[i] - 'a']++;

            charFrequency[t[i] - 'a']++;
        }
      
        for(int i = 0;i<26;i++){
            if(charFrequency[i] != 0){
                return false;
            }
        }

        return true;

        // return all_of(charFrequency.begin(), charFrequency.end(), 
        //              [](int count) { return count == 0; });
        
    }
};