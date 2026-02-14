class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end());
	    int p = a[m-1]-a[0];
	    for(int i = 0;i < n-m+1; i++){
	        if(p>(a[i+m-1]-a[i])) 
	            p = (a[i+m-1]-a[i]);
	    }
	    return p;
    }
};
