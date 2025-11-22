class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();

        string ans = strs[0];

        for(int i = 1;i<n;i++){

            int j = 0;

            while(j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j]){
                j++;
            }

            ans.erase(j);


            if(ans == ""){
                return "";
            }

        }


        return ans;
        
    }
};