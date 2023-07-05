#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	vector<int> ans;
	priority_queue<int> pq;
	for(auto it:arr) pq.push(it);

   int temp = k;
	while(!pq.empty() && k!=1){
		pq.pop();
		k--;
	}
	ans.push_back(pq.top());

    priority_queue<int,vector<int>,greater<int>> pq1;
	for(auto it:arr) pq1.push(it);

	while(!pq1.empty() && temp!=1) {
		pq1.pop();
		temp--;
	}
	ans.push_back(pq1.top());
 int curr = ans[0];
 ans[0] = ans[1];
 ans[1] = curr;
	return ans;

}
// #include<bits/stdc++.h>
// vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
//   // Write your code here.
//   vector<int> ans;
//   sort(arr.begin(),arr.end());
//   ans.push_back(arr[k-1]);
//   ans.push_back(arr[arr.size()-k]);
//   return ans;
// }