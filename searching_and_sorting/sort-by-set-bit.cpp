 public:
    // int countBits(int a)
    // {
    //     int count = 0;
    //     while (a) {
    //         if (a & 1){
    //             count += 1;   
    //         }
    //         a = a >> 1;
    //     }
    //     return count;
    // }
     
    // void insertionSort(int arr[], int aux[], int n)
    // {
    //     for (int i = 1; i < n; i++) {
    //         // use 2 keys because we need to sort both arrays simultaneously
    //         int key1 = aux[i];
    //         int key2 = arr[i];
    //         int j = i - 1;
     
    //         // Move elements of arr[0..i-1] and aux[0..i-1],
    //         // such that elements of aux[0..i-1] are greater
    //         // than key1, to one position ahead of their current
    //         // position
    //         while (j >= 0 && aux[j] < key1) {
    //             aux[j + 1] = aux[j];
    //             arr[j + 1] = arr[j];
    //             j = j - 1;
    //         }
    //         aux[j + 1] = key1;
    //         arr[j + 1] = key2;
    //     }
    // }
    
    static int cmp(int a,int b)
    {
        int count1 = __builtin_popcount(a);
        int count2 = __builtin_popcount(b);
    
        // this takes care of the stability of
        // sorting algorithm too
        if (count1 <= count2)
            return false;
        return true;
    }
      
    void sortBySetBitCount(int arr[], int n)
    {
        // // Create an array and store count of set bits in it.
        // int aux[n];
        // for (int i = 0; i < n; i++)
        //     aux[i] = countBits(arr[i]);
     
        // // Sort arr[] according to values in aux[]
        // insertionSort(arr, aux, n);
        
        stable_sort(arr, arr+n, cmp);
    }