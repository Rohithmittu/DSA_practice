#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){

    int s = 0;
    int e = nums.size() - 1;
    while(s<e){
        if(nums[e]<0 && nums[s]>0){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }else if(nums[s] < 0 ){
            s++;
        }
        else{
            e--;
        }
    }
    return nums;
}