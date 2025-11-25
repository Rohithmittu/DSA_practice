class Solution {
public:


    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &temp, int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums,ans,temp,i+1);
        temp.pop_back();


        int idx = i+1;

        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }

        solve(nums,ans,temp,idx);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<int> temp;
        vector<vector<int>> ans;

        solve(nums,ans,temp,0);

        return ans;
        
    }
};