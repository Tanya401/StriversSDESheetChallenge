int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int j = 0;
	for(int i=0;i<n;i++){
     if(arr[i]!=arr[j]){
        j++;
		arr[j] = arr[i];
	 }
	}
	return j+1;
}
// 1 2 2 3 3
// 1 2 3 