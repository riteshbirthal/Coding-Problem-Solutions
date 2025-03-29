class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        long long ans = 0;
        int n = arr.size(), prev = 0, next = n-1, temp, flag = 1;
        for(int i = 1; i < n; i++){
            ans += abs(arr[next]-arr[prev]);
            if(flag){
                temp = prev;
                prev = next;
                next = temp + 1;
            }else{
                temp = prev;
                prev = next;
                next = temp - 1;
            }
            flag = !flag;
        }
        ans += abs(arr[prev] - arr[0]);
        return ans;
    }
};
