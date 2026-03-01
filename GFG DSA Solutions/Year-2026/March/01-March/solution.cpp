// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size(), ptr = 0, z_idx = 0;
        while(z_idx<n && ptr<n){
            if(arr[z_idx]==0){
                while(ptr<n && arr[ptr]==0)
                    ptr++;
                if(ptr<n){
                    arr[z_idx] = arr[ptr];
                    arr[ptr] = 0;
                }
            }else{
                z_idx++;
            }
            if(ptr<n && (ptr<=z_idx || arr[ptr]==0))
                ptr++;
        }
        return ;
    }
};
