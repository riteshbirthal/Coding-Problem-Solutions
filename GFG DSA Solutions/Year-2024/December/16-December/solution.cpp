class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i = 0, j = 0, n1 = a.size(), n2 = b.size();
        k--;
        while((i<n1 || j < n2) && k--){
            if(i<n1 && j<n2){
                a[i]<b[j] ? i++ : j++;
            }else if(i<n1){
                i++;
            }else{
                j++;
            }
        }
        return i<n1 && j<n2 ? min(a[i], b[j]) : (i<n1 ? a[i] : b[j]);
    }
};