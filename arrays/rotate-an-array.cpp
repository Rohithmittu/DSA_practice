vector<int> rotateArray(vector<int>arr, int k) {
    vector<int>ans;
    for(int i=k;i<arr.size();i++){
        ans.push_back(arr[i]);
    }
    for(int i = 0;i<k;i++){
        ans.push_back(arr[i]);
    }

    return ans;

      
}
