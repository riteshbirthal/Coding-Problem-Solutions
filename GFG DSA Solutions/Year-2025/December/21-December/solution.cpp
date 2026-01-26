class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> res;
        int left, right, mid, l_idx, r_idx;
        for(auto &q : queries){
            left = r_idx = q[0], right = l_idx = q[1];
            while(left <= right){
                mid = (left + right) / 2;
                if(arr[mid]==q[2]){
                    l_idx = mid;
                    right = mid - 1;
                }else if(arr[mid]>q[2]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            left = q[0], right = q[1];
            while(left <= right){
                mid = (left + right) / 2;
                if(arr[mid]==q[2]){
                    r_idx = mid;
                    left = mid + 1;
                }else if(arr[mid] > q[2]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            if(arr[l_idx]==arr[r_idx] && arr[l_idx]==q[2])
                res.push_back(r_idx - l_idx + 1);
            else
                res.push_back(0);
        }
        return res;
    }
};
