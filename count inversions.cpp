#include <bits/stdc++.h> 

long long merge(int start,int mid,int end,long long *arr){
   long long count = 0;
    vector<int> temp;
    int left = start, right = mid+1;
    while(left<=mid && right<=end){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            count+= (mid-left)+1;
           temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
       temp.push_back(arr[left]);
       left++;
    }
    while(right<=end){
       temp.push_back(arr[right]);
       right++;
    }
    for(int i=start;i<=end;i++){
        arr[i]=temp[i-start];
    }
    return count;
}
long long mergesort(int start,int end,long long *arr){
    long long count = 0;
    if(start>=end) return count;

    int mid = (start+end)/2;
   count +=  mergesort(start,mid,arr);
   count +=  mergesort(mid+1,end,arr);
   count += merge(start,mid,end,arr);

   return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    int start = 0;
    int end = n-1;
    return mergesort(start,end,arr);
}