// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int mx = *max_element(citations.begin(), citations.end());
        vector<int> vec(mx + 1, 0);
        for(int x : citations)
            vec[x]++;
        for(int i = mx; i>0; i--)
            vec[i-1] += vec[i];
        for(int i = mx; i>=0; i--)
            if(vec[i]>=i) return i;
        return -1;
    }
};