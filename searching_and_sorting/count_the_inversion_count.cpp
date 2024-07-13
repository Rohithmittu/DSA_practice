//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long my_counter = 0;

    // p: initial point in the array, say left index
    // q: mid point
    // r: higher range
    // Function to sort and merge two parts of array.
    void merge(long long arr[], long long p, long long q, long long r) {
        long long l = q - p + 1;
        long long arr1[l];

        long long l2 = r - q;

        long long arr2[l2];

        // Storing elements present in left half in the array a1.
        for (long long i = 0; i < l; i++) {
            arr1[i] = arr[i + p];
        }
        // Storing elements present in right half in the array a2.
        for (long long i = 0; i < l2; i++) {
            arr2[i] = arr[q + i + 1];
        }

        long long left = 0, right = 0, k = p;

        // Using two pointers over the two arrays which helps in storing the
        // smaller element and thus merging the array.
        while (left < l && right < l2) {
            // Comparing element of the arrays a1 and a2 at pointers left and
            // right and accordingly storing the smaller element and updating
            // the pointers.
            if (arr1[left] <= arr2[right]) {
                arr[k] = arr1[left];
                left++;
            } else {
                arr[k] = arr2[right];
                right++;
                // Adding the inversions which is the number of elements which
                // are smaller than a2[right] in the a1 array.
                my_counter += (l - left);
            }
            k++;
        }
        // Storing  the remaining elements of left subarray(if there are any)
        // in the array a1.
        while (left < l) {
            arr[k++] = arr1[left++];
        }
        // Storing the remaining elements of right subarray(if there are any)
        // in the array a2.
        while (right < l2) {

            arr[k++] = arr2[right++];
        }
    }

    // Function to mergesort the array, which uses divide and conquer algorithm
    // on left and right halves of array for mergesort operation.
    void mergeSort(long long arr[], long long p, long long r) {
        if (p < r) {
            long long q = (p + r) / 2;
            // Calling recursive function to sort left half of the array.
            mergeSort(arr, p, q);

            // Calling recursive function to sort right half of the array.
            mergeSort(arr, q + 1, r);

            // Calling merge function which sorts and merges both halves
            // of the array obtained after calling both recursive function.
            merge(arr, p, q, r);
        }
    }

    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        
        
        // int i,j,counter = 0;
        // for(i=0;i<n;i++){
        //     for(j=0;j<i;j++){
        //         if(arr[j] > arr[i])
        //         counter++;
        //     }
        // }
        // return counter;
        
        
        mergeSort(arr, 0, n - 1);
        long long int res = my_counter;
        my_counter = 0;
        // returning the count of inversions in the array.
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends