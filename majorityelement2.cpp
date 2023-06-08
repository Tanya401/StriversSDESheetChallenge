#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
    int cnt1 = 0, cnt2 = 0;
        int ele = INT_MIN, ele2 = INT_MIN;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(cnt1 == 0 && ele2!=nums[i]){
                cnt1++;
                ele = nums[i];
            }
           else if(cnt2 == 0 && ele!=nums[i]){
                cnt2++;
                ele2 = nums[i];
            }
            else if(nums[i] == ele) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
      int temp1 = 0,temp2=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i] == ele) temp1++;
     }
     for(int i=0;i<nums.size();i++){
        if(nums[i] == ele2) temp2++;
     }
     vector<int> ans;
    if(temp1 >= (int(n/3)+1)) 
    ans.push_back(ele);
    if(temp2 >= (int(n/3)+1))
    ans.push_back(ele2);
    return ans;
}