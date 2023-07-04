void find(int ind,vector<int>&num,int sum,vector<int>&ans){
	if(ind < 0){
		ans.push_back(sum);
		return;
	}
	find(ind-1,num,sum,ans);

	sum += num[ind];

	find(ind-1,num,sum,ans);

	sum -= num[ind];
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> ans;
	if(num.empty()) return ans;
	int n = num.size();
	find(n-1,num,0,ans);
	sort(ans.begin(),ans.end());
    return ans;
}