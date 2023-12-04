long long getTrappedWater(long long* arr, int n) {

    // Write your code here.

    long long right = n-1;

    long long left = 0;

    long long maxleft = 0;

    long long maxright = 0;

    long long res=0;

    while(left<=right)

    {

       if(arr[left]<=arr[right])

       {

           if(arr[left]>=maxleft)

           {

               maxleft = arr[left];

           }

           else{

               res+=maxleft-arr[left];

           }

           left++;

       }

       else{

           if(arr[right]>=maxright)

           {

               maxright = arr[right];

           }

           else{

               res+=maxright-arr[right];

           }

           right--;

       }

    }

    return res;

}