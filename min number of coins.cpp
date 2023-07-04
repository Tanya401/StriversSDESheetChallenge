// #include <bits/stdc++.h> 
// int find(int ind,int n,vector<int>&nums,int amount,vector<vector<int>>&dp){
//     if(ind < 0) return INT_MAX;
//     if(amount == 0) return 0;
//     if(dp[ind][amount]!=-1) return dp[ind][amount];
//     int take = INT_MAX;
//     if(nums[ind]<=amount)
//     take = 1 + find(ind,n,nums,amount-nums[ind],dp);

//     int nottake = find(ind-1,n,nums,amount,dp);

//     return dp[ind][amount] = min(take,nottake);
// }
// int findMinimumCoins(int amount) 
// {
//     // Write your code here
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(2);
//     nums.push_back(5);
//     nums.push_back(10);
//     nums.push_back(20);
//     nums.push_back(50);
//     nums.push_back(100);
//     nums.push_back(500);
//     nums.push_back(1000);

//     int n = nums.size();
//     vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//     return find(n-1,n,nums,amount,dp);
    
// }


int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(50);
    nums.push_back(100);
    nums.push_back(500);
    nums.push_back(1000);

    int n = nums.size();
    int c = 0;
   for(int i=n-1;i>=0;i--){
       while(amount>=nums[i]){
           amount -= nums[i];
           c++;
       }
   }
    return c;
}

