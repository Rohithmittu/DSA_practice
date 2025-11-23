class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // unordered_map<string, vector<string>> mp;

        // for (string s : strs) {
        //     string key = s;
        //     sort(key.begin(), key.end());  // sorted version becomes the key
        //     mp[key].push_back(s);
        // }

        // vector<vector<string>> ans;
        // for (auto pair : mp) {
        //     ans.push_back(pair.second);
        // }

        // return ans;

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            // create frequency array for each string
            int count[26] = {0};

            for (char c : s) {
                count[c - 'a']++;
            }

            // convert frequency array into a unique key string
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &p : mp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};


