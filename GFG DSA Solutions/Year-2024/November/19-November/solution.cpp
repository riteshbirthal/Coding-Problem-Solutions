// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size(), idx = -1;
        for(int i = n-1; i > 0; i--){
            if(arr[i]>arr[i-1]){
                idx = i-1;
                break;
            }
        }
        if(idx==-1){
            sort(arr.begin(), arr.end());
            return ;
        }
        vector<int> vec(arr.begin() + idx + 1, arr.end());
        sort(vec.begin(), vec.end());
        int flag = 1;
        for(int i = idx+1; i < n && flag; i++){
            if(flag && vec[i-idx-1]>arr[idx]){
                flag = arr[idx];
                arr[idx] = vec[i-idx-1];
                vec[i-idx-1] = flag;
                flag = 0;
            }
        }
        sort(vec.begin(), vec.end());
        for(int i = idx+1; i < n; i++)
            arr[i] = vec[i-idx-1];
        return ;
    }
};