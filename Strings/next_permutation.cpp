class Solution{
public:
    // Function to find the next permutation
    vector<int> nextPermutation(int N, vector<int> arr){
        int ind = 0;
        vector<int> v = arr;
        
        // Finding the first decreasing element from right to left
        for(int i = N-2;i >= 0;i--){
            if(v[i] < v[i+1]){
                ind = i;
                break;
            }
        }
        
        // Finding the smallest element greater than the element at ind
        for(int i = N-1;i > ind;i--){
            if(v[i] > v[ind]){
                swap(v[i], v[ind]);
                ind++;
                break;
            }
        }
        
        // Reversing the elements from ind to end
        for(int i = 0;i < (N-ind)/2;i++)
            swap(v[i+ind], v[N-i-1]);
        
        // Returning the next permutation
        return v;
    }
};