class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int ans = INT_MAX, n = arr.size(), left = 0, right = n - 1, mid;
        while(left<=right){
            mid = (left+right)/2;
            if(arr[left]>=arr[right]){
                ans = min(ans, arr[mid]);
                if(arr[mid]<arr[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                ans = min(ans, arr[left]);
                break;
            }
        }
        return ans;
    }
};