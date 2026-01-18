class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int left = 0, right = 0, n = arr.size(), odds = 0, r_count, l_count, res = 0;
        while(right < n){
            if(arr[right]%2)
                odds++;
            if(odds<k){
                right++;
                continue;
            }
            r_count = 1;
            right += 1;
            while(right < n && arr[right]%2==0)
                r_count += 1, right++;
            l_count = 1;
            while(arr[left]%2==0)
                left++, l_count++;
            left += 1;
            res += l_count * r_count;
            odds--;
        }
        return res;
    }
};
