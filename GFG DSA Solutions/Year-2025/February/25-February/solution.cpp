class Solution {
    public:
      int getMaxArea(vector<int> &arr) {
          // Your code here
          int n = arr.size(), res = 0;
          vector<int> left(n), right(n);
          stack<int> l, r;
          for(int i = 0; i < n; i++){
              if(!l.empty()){
                  while(!l.empty() && arr[l.top()]>=arr[i])
                      l.pop();
                  left[i] = l.empty() ? i+1 : i - l.top();
              }else{
                  left[i] = i+1;
              }
              l.push(i);
              if(!r.empty()){
                  while(!r.empty() && arr[r.top()]>=arr[n-1-i])
                      r.pop();
                  right[n-1-i] = r.empty() ? i+1 : r.top() - n + 1 + i;
              }else{
                  right[n-1-i] = i+1;
              }
              r.push(n-1-i);
          }
          for(int i = 0; i < n; i++)
              res = max(res, (left[i] + right[i] - 1) * arr[i]);
          return res;
      }
  };
  