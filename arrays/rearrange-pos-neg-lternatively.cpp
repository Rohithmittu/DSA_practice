#include <bits/stdc++.h> 

void rearrange(vector<int> &arr)
{
	 int n = arr.size();
    
    // Separate positive and negative numbers
    std::vector<int> pos, neg;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        } else {
            neg.push_back(arr[i]);
        }
    }

    int i = 0, j = 0, k = 0;

    // Merge positive and negative numbers alternatively
    while (i < pos.size() && j < neg.size()) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }

    // If there are remaining positive numbers, append them to the result
    while (i < pos.size()) {
        arr[k++] = pos[i++];
    }

    // If there are remaining negative numbers, append them to the result
    while (j < neg.size()) {
        arr[k++] = neg[j++];
    }


}