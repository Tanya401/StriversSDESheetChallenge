 #include<bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n = heights.size();
   int left[n], right[n];
   stack<int> st;
   //left small
   for(int i=0;i<n;i++){
     while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
     if(st.empty()) left[i] = 0;
     else left[i] = st.top()+1;
     st.push(i);
   }
   //clear the stack
while(!st.empty()) st.pop(); 

   //right small
   for(int i=n-1;i>=0;i--){
     while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
     if(st.empty()) right[i] = n-1;
     else right[i] = st.top()-1;
     st.push(i);
   }

   int maxi = INT_MIN;
   for(int i=0;i<n;i++){
     int area = (right[i]-left[i]+1)*heights[i];
     maxi = max(maxi,area);
   }
   return maxi;
 }