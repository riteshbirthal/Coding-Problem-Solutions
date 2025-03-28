class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size(), left, right, mid, l_idx = -1, r_idx = -1;
        left = 0, right = n-1;
        while(left<=right){
            mid = (left + right) / 2;
            if(arr[mid]<target){
                left = mid + 1;
            }else if(arr[mid]>target){
                right = mid-1;
            }else{
                l_idx = mid;
                right = mid - 1;
            }
        }
        left = 0, right = n-1;
        while(left<=right){
            mid = (left + right) / 2;
            if(arr[mid]<target){
                left = mid + 1;
            }else if(arr[mid]>target){
                right = mid-1;
            }else{
                r_idx = mid;
                left = mid + 1;
            }
        }
        return l_idx==-1 || r_idx==-1 ? 0 : r_idx-l_idx+1;
    }
};
