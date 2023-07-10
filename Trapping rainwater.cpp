long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    int left = 0, right = n-1;
    long long rain = 0;
    long long leftmax = 0,rightmax = 0;
   while(left<=right){
       if(arr[left]<=arr[right]){
         if(arr[left]>leftmax) leftmax = arr[left];
         else rain += (leftmax-arr[left]);
         left++;
       }
       else{
        if(arr[right]>rightmax) rightmax=arr[right];
        else rain += (rightmax-arr[right]);
        right--;
       }
    }
    return rain;
}