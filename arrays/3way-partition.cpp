void threewaypartitioning(int arr[], int n, int l, int h)
{
  int begin = 0, end = n-1; 
  for(int i = 0; i <= end; i++)
  {
    if(arr[i] < l)
    {
      swap(arr[i], arr[begin]);
      begin++;  
    }
    else if(arr[i] > h)
    {
      swap(arr[i], arr[end]);
      i--;
      end--;
    }
  }
}
