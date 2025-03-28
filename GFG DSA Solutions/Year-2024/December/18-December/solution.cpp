class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), ans = INT_MAX, left = *max_element(arr.begin(), arr.end()), right = 1e9, mid, count, sum, flag;
        if(k>n) return -1;
        while(left<=right){
            mid = (left + right) / 2;
            count = k-1, sum = 0, flag = 1;
            for(int i = 0; i < n; i++){
                if(sum + arr[i] > mid){
                    if(sum == 0){
                        flag = 0;
                        break;
                    }else{
                        sum = arr[i];
                        count--;
                    }
                }else{
                    sum += arr[i];
                }
            }
            if(!flag || count<0){
                left = mid + 1;
            }else{
                ans = min(ans, mid);
                right = mid - 1;
            }
        }
        return ans;
    }
};