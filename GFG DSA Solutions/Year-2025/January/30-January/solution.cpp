// User function Template for C++

class Solution {
    public:
      bool check(vector<vector<int>> &vec, int r, int c, int n){
          for(int i = r-1; i >= 0; i--) if(vec[i][c]==1) return false;
          for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) if(vec[i][j]==1) return false;
          for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++) if(vec[i][j]==1) return false;
          return true;
      }
      
      vector<vector<vector<int>>> func(int n, int m){
          if(m==0){
              vector<vector<int>> vec;
              vector<int> v;
              for(int i = 0; i < n; i++)  v.push_back(0);
              for(int i = 0; i < n; i++) vec.push_back(v);
              vector<vector<vector<int>>> ans;
              for(int i = 0; i < n; i++){
                  vec[m][i] = 1;
                  ans.push_back(vec);
                  vec[m][i] = 0;
              }
              return ans;
          }
          vector<vector<vector<int>>> ans, vec;
          vector<vector<int>> temp;
          vec = func(n, m-1);
          for(int i = 0; i < vec.size(); i++){
              temp = vec[i];
              for(int j = 0; j < n; j++){
                  if(check(temp, m, j, n)){
                      temp[m][j] = 1;
                      ans.push_back(temp);
                      temp[m][j] = 0;
                  }
              }
          }
          return ans;
      }
      
      vector<vector<int>> convertResult(vector<vector<vector<int>>>& res){
          vector<vector<int>> vec;
          for(auto r : res){
              vector<int> v;
              int n = r.size();
              for(int i = 0; i < n; i++){
                  for(int j = 0; j < n; j++){
                      if(r[i][j])
                          v.push_back(j+1);
                  }
              }
              vec.push_back(v);
          }
          return vec;
      }
      
      vector<vector<int>> nQueen(int n) {
          // code here
          vector<vector<vector<int>>> vec;
          vec = func(n, n-1);
          vector<vector<int>> res;
          res = convertResult(vec);
          return res;
      }
  };