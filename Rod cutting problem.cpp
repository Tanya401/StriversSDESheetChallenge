int find(int ind,int n,vector<int>&price,vector<vector<int>>&dp){
  if(ind == 0){
	   return n*price[ind];
  }
  if(dp[ind][n]!=-1) return dp[ind][n];
  int take = INT_MIN;
  if(ind+1<=n)
  take = price[ind] + find(ind,n-(ind+1),price,dp);

  int nottake = find(ind-1,n,price,dp);

  return dp[ind][n] = max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int size = price.size();
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return find(n-1,n,price,dp);
}
