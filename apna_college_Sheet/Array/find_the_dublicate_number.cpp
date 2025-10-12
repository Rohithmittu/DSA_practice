class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        // sort(nums.begin(),nums.end());

        // for(int i = 0;i<nums.size();i++){
        //     if(nums[i] == nums[i+1]){
        //         return nums[i];
        //     }
        // }

        // return -1;

        // O(nlogn);

        // unordered_set<int> s;

        // for(int val: nums){
        //     if(s.find(val) != s.end()){
        //         return val;
        //     }

        //     s.insert(val);
        // }

        // return -1;

        int slow = nums[0], fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};