class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int cnt = 0;
        // for(int i = 0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j = i;j<nums.size();j++){

        //         sum += nums[j];

        //         if(sum == k){
        //             cnt++;
        //         }

        //     }
        // }

        // return cnt;

        // TC --O(n^2)

        int n = nums.size();
        vector<int> prefix(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int cnt = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {

            if (prefix[i] == k) {
                cnt++;
            }

            int val = prefix[i] - k;

            if (m.find(val) != m.end()) {

                cnt += m[val];
            }

            if (m.find(prefix[i]) == m.end()) {
                m[prefix[i]] = 0;
            }
            m[prefix[i]]++;
        }

        return cnt;
    }
};