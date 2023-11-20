
void sort012(int *arr, int n)
{
    int i=0;
    int count[3] ={ 0, 0, 0 };

    //  Storing Count of 0s, 1s and 2s
    for (i=0;i<n;i++)
    {
        count[arr[i]]++;
    }


    i=0;

    //  First filling 0
    while (count[0]--)
    {
        arr[i++]=0;
    }

    //  Then filling 1
    while (count[1]--)
    {
        arr[i++]=1;
    }

    // Then filling 2
    while (count[2]--)
    {
        arr[i++]=2;
    }
}