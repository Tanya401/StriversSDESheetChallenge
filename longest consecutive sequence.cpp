#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    // Write your code here.
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) mp[nums[i]]=1;

    int ans = 0;
    for(int i=0;i<n;i++){
        int curr = nums[i];
        int temp = 1;
        if(mp.find(curr-1)==mp.end()){
            while(mp.find(curr+1)!=mp.end()){
                curr=curr+1;
                temp++;
            }
            ans = max(ans,temp);
        }
    }
    return ans;
}