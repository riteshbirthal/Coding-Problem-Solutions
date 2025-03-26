class Solution {
    public:
      vector<int> maxOfMins(vector<int>& arr) {
          // Your code here
          int n = arr.size(), top;
          vector<int> res(n, 0), len(n, 0);
          stack<int> st;
          for(int i = 0; i < n; i++){
              while(!st.empty() && arr[st.top()]>=arr[i]){
                  top = st.top(), st.pop();
                  len[top] = st.empty() ? i : i-st.top()-1;
              }
              st.push(i);
          }
          while(!st.empty()){
              top = st.top(), st.pop();
              len[top] = st.empty() ? n : n-st.top()-1;
          }
          for(int i = 0; i < n; i++)
              res[len[i]-1] = max(res[len[i]-1], arr[i]);
          for(int i = n-2; i >= 0; i--)
              res[i] = max(res[i], res[i+1]);
          return res;
      }
  };
  