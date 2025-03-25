class Solution {
    public:
      string decodedString(string &s) {
          // code here
          stack<string> st;
          stack<int> nums;
          st.push("");
          string num = "";
          for(char ch : s){
              if('0'<=ch && ch<='9'){
                  num += ch;
              }else if(ch=='['){
                  nums.push(stoi(num));
                  st.push("");
                  num = "";
              }else if(ch==']'){
                  string temp = st.top(), newTop = "";
                  st.pop();
                  for(int i = 0; i < nums.top(); i++){
                      newTop += temp;
                  }
                  st.top() += newTop;
                  nums.pop();
              }else{
                  st.top() += ch;
              }
          }
          return st.top();
      }
};