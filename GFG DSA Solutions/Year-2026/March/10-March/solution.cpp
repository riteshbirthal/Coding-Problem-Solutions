class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size(), res = 0;
        stack<int> stk;
        stk.push(n);
        for(int i = n-1; i >= 0; i--){
            while(stk.top()!=n && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            res += stk.top()-i;
            stk.push(i);
        }
        return res;
    }
};
