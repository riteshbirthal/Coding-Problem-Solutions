class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), res = 0, left = 0, right = 0;
        while(right<n){
            while(right<n && (k || arr[right]==1)){
                if(arr[right]==0)
                    k -= 1;
                right += 1;
                res = max(res, right - left);
            }
            while(left<right && arr[left]==1)
                left++;
            if(arr[left]==0)
                left += 1, k += 1;
        }
        return res;
    }
};
