
int minCharsforPalindrome(string str) {
	// Write your code here.
	int i = 0, j = str.size()-1;
	int res = 0, trim = j;
  while(i<=j){
	  if(str[i]==str[j]){
		  i++;
		  j--;
	  }
	  else{
       res ++;
	   j =  --trim;
	   i=0;
	  }
  } 
	return res;
}
