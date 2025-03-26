class Solution {
    public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          // Your code here
          vector<vector<int>> res, vec;
          for(auto v : points){
              vec.push_back({v[0]*v[0] + v[1]*v[1], v[0], v[1]});
          }
          sort(vec.begin(), vec.end());
          for(int i = 0; i < k; i++){
              res.push_back({vec[i][1], vec[i][2]});
          }
          return res;
      }
  };