// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n = mat.size(), m = mat[0].size(), left, right, mid;
        for(int i = 0; i < n; i++){
            if(x<mat[i][0] || mat[i][m-1]<x)
                continue;
            left = 0, right = m-1;
            while(left<=right){
                mid = (left + right) / 2;
                if(mat[i][mid]==x)
                    return true;
                else if(mat[i][mid]<x)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};