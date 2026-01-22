class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n = arr.size(), res = 0;
        stack<int> stk;
        vector<int> vec(n, 0);
        stk.push(-1);
        for(int i = 0; i < n; i++){
            while(stk.top()!=-1 && arr[stk.top()]<arr[i])
                stk.pop();
            vec[i] += i-stk.top()-1;
            stk.push(i);
        }
        while(stk.size())
            stk.pop();
        stk.push(n);
        for(int i = n-1; i >= 0; i--){
            while(stk.top()!=n && arr[stk.top()]<arr[i])
                stk.pop();
            vec[i] += stk.top()-1-i;
            stk.push(i);
        }
        for(int i = 0; i < n; i++)
            res = max(res, vec[i]);
        return res + 1;
    }
};
