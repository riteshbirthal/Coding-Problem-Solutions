class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size(), count = 0, idx = 0;
        for(int i = 0; i < n; i++){
            arr[i] = (arr[i]%k + k)%k;
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            if(arr[i]==0)
                count++;
        }
        if(count%2)
            return false;
        for(int i = count; i < n-1-idx; i++, idx++){
            if((arr[i]+arr[n-1-idx])%k)
                return false;
        }
        return true;
    }
};