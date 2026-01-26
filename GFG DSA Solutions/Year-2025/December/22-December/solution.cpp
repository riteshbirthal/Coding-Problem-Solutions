// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size(), m = arr[0].size(), left, right, mid, res = -1, max_count = 0, count;
        for(int i = 0; i < n; i++){
            left = 0, right = m - 1, count = 0;
            while(left <= right){
                mid = (left + right) / 2;
                if(arr[i][mid]){
                    count = m - mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            if(count > max_count){
                max_count = count;
                res = i;
            }
        }
        return res;
    }
};
