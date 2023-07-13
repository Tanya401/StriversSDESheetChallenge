#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int> maxi;
	priority_queue<int,vector<int>,greater<int>> mini;
	vector<int> ans;
	for(int i=0;i<n;i++){
   if(maxi.size() == 0 || maxi.top()>=arr[i]) maxi.push(arr[i]);
   else mini.push(arr[i]);

   if(maxi.size() > mini.size()+1){
	   mini.push(maxi.top());
	   maxi.pop();
   }
   else if(mini.size() > maxi.size()+1){
	   maxi.push(mini.top());
	   mini.pop();
   }
   if(mini.size() == maxi.size()){
	   ans.push_back((mini.top()+maxi.top())/2);
   }
   else{
	   if(maxi.size()>mini.size()) ans.push_back(maxi.top());
	   else ans.push_back(mini.top());
   }
	}
	return ans;
}
