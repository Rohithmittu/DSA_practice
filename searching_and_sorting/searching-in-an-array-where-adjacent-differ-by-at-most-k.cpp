int search(int arr[], int n, int x, int k)
{
    // for(int i=0;i<n;i++){
    //   if(x==arr[i]){
    //      return i;
    //   }
    // }
    // return -1;
    // Travers the given array starting from
	// leftmost element
	int i = 0;
	while (i < n)
	{
		// If x is found at index i
		if (arr[i] == x)
			return i;

		// Jump the difference between current
		// array element and x divided by k
		// We use max here to make sure that i
		// moves at-least one step ahead.
		i = i + max(1, abs(arr[i]-x)/k);
	}

	return -1;
} 