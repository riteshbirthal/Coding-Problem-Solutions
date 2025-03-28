class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int ans = -1, n = arr.size(), left = 0, right = n - 1, mid, idx, mn = INT_MAX;
        while(left<=right){
            mid = (left+right)/2;
            if(arr[left]>=arr[right]){
                if(mn>arr[mid]){
                    mn = arr[mid];
                    idx = mid;
                }
                if(arr[mid]<arr[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(mn>arr[left]){
                    mn = arr[left];
                    idx = left;
                }
                break;
            }
        }
        if(key<=arr[n-1]){
            left = idx, right = n-1;
        }else{
            left = 0, right = idx-1;
        }
        while(left<=right){
            mid = (left + right) / 2;
            if(arr[mid]==key){
                return mid;
            }else if(arr[mid]<key){
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }
        return ans;
    }
};