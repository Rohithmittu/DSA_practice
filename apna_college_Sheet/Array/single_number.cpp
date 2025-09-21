class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int> freq;

        // for(int num : nums){
        //     freq[num]++;
        // }

        // for(auto &p : freq){
        //     if(p.second == 1){
        //         return p.first;
        //     }
        // }
        // return -1; 

        int ans = 0;


        for(int i = 0;i<nums.size();i++){

            ans ^= nums[i];



        }

        return ans;
    }
};
