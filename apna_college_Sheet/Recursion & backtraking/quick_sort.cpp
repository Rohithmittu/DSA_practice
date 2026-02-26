class Solution {
public:

    int partition(vector<int>& nums,int start,int end){

        int idx = start - 1;
        int pivot = nums[end];

        for(int i = start;i< end;i++){
            if(nums[i] <= pivot ){
                idx++;
                swap(nums[idx],nums[i]);
            }
        }
        idx++;
        swap(nums[idx],nums[end]);


        return idx;

    }

    void quicksort(vector<int>& nums,int start, int end){
        
        if(start < end){

            int pivot = partition(nums,start,end);

            quicksort(nums,start,pivot - 1);
            quicksort(nums,pivot+1,end);
        }

    }

    vector<int> sortArray(vector<int>& nums) {

        quicksort(nums,0,nums.size()-1);

        return nums;
        
    }
};


// worst case time complexity: O(n^2) when the array is already sorted or reverse sorted
// average case time complexity: O(n log n)
// best case time complexity: O(n log n) when the pivot divides the array into two equal halves
// space complexity: O(log n) on average due to recursive stack space, O(n)