class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size(), left = 0, right = matrix[n-1][n-1], mid, res = -1, count;
        while(left<=right){
            mid = (left + right) / 2;
            count = 0;
            for(int i = 0; i < n; i++){
                int l = 0, r = n-1, m, rs = 0;
                while(l<=r){
                    m = (l+r)/2;
                    if(matrix[i][m]<=mid){
                        rs = m+1;
                        l = m+1;
                    }else{
                        r = m-1;
                    }
                }
                count += rs;
            }
            if(count>=k){
                res = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return res;
    }
};
