class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // int n = arr.size();

        // int max = 0;

        // for (int i = 0; i < n; i++) {

        //     if (arr[i] > arr[max]) {
        //         max = i;
        //     }
        // }

        // return max;

        int n = arr.size();

        int s = 0,e = n-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]){
                return mid;
            }

            if(arr[mid - 1] < arr[mid]){
                s = mid + 1;
            }else{
                e = mid;
            }

        }

        return -1;
    }
};