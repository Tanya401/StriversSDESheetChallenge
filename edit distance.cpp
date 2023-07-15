#include<bits/stdc++.h>
int find(int i,int j,string &str1,string &str2, int s,int t,vector<vector<int>>&dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
   if(dp[i][j]!=-1) return dp[i][j];
   
    if(str1[i] == str2[j]) 
    return dp[i][j] = 0 + find(i-1,j-1,str1,str2,s,t,dp);
  
    return dp[i][j] = min(1+find(i,j-1,str1,str2,s,t,dp),
    min(1+find(i-1,j,str1,str2,s,t,dp),1+find(i-1,j-1,str1,str2,s,t,dp)));
    
}

int editDistance(string str1, string str2)
{
    //write you code here
    int s = str1.size();
    int t = str2.size();
    vector<vector<int>> dp(s,vector<int>(t,-1));
    
    return find(s-1,t-1,str1,str2,s,t,dp);
}