#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	// Write your code here.
	//start from the back of arr1
	
	int i = m-1, j = 0;
        while(i>=0 && j<n){
            if(nums1[i]<=nums2[j]) break;
            else {
               swap(nums1[i],nums2[j]);
               i--;
               j++; 
            }
        }
         j = 0;
     for(int k=m;k<m+n;k++) nums1[k] = nums2[j++];
     sort(nums1.begin(),nums1.end());
	 return nums1;
}