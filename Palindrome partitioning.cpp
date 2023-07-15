#include <bits/stdc++.h> 
bool ispal(int i,int j,string&str){
    while(i<=j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}
int find(int i,int n,string &str,vector<int>&dp){
 if(i == n) return 0;
 if(dp[i]!=-1) return dp[i];
  int mini = INT_MAX;
    for(int j=i;j<n;j++){
        if(ispal(i,j,str)){
           int cost = 1 + find(j+1,n,str,dp);
            mini = min(mini,cost);
        }
    }
    return dp[i] = mini;
}
int palindromePartitioning(string str) {
    // Write your code here
    int size = str.size();
    vector<int> dp(size,-1);
    return find(0,size,str,dp)-1;
}
