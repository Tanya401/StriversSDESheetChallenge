int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int left = 0, right = 0;
    int ones = 0, zero = 0,maxlen=0;
    while(right<n){
        if(arr[right]==0) zero++;
        if(arr[right]==1) ones++;
        while(left<right && zero>k){
        if(arr[left]==0) zero--;
        else ones--;
        left++;
                }
        maxlen = max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}
