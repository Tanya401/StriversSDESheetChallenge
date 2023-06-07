#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    int maxp = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        maxp=max(maxp,sum);
        if(sum<0) sum = 0;
    }
    if(maxp < 0) return 0;
    return maxp;
}