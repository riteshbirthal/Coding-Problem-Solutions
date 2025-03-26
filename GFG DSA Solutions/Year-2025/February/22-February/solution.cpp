
class Solution {
    public:
      int maxLength(string& s) {
          // code here
          int ans=0,count=0;
          stack<pair<char, int>> st;
          st.push({' ', -1});
          for(int i=0; i<s.size(); i++){
              if(st.size()==1 && s[i]==')') st.top().second = i, count = 0;
              else if(s[i]==')') st.pop(), count = i - st.top().second;
              else st.push({'(',  i}), count=0;
              ans = max(ans, count);
          }
          return ans;
      }
  };