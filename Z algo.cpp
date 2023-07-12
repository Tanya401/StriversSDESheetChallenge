int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	int occ=0;
	for(int i=0;i<s.size();i++){
     if(s[i]==p[0] && (i+m-1<n))
	 {
		 if(p == s.substr(i,m)) occ++;
	 }
	}
	return occ;
}