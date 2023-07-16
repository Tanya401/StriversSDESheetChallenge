int search(int* arr, int n, int target) {
    // Write your code here.
    int low = 0,end=n-1;
    while(low<=end){
   int mid = (low+end)/2;
   if(arr[mid]==target) return mid;
   else if(arr[low]<=arr[mid]){
    if(arr[low]<=target && target<=arr[mid]) end=mid-1;
    else low=mid+1;
   }
   else{
       if(arr[mid]<=target && target<=arr[end]) low=mid+1;
       else end=mid-1;
   }
    }
    return -1;
}