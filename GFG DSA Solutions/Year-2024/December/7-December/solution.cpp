class Solution {
  public:
    // Function to count inversions in the array.
    int countInv(vector<int>& vec, int left, int right){
        if(left>=right) 
            return 0;
        int ans = 0, mid;
        mid = (left + right)/2;
        ans += countInv(vec, left, mid);
        ans += countInv(vec, mid+1, right);
        vector<int> left_vec, right_vec;
        for(int i = left; i <= mid; i++){
            left_vec.push_back(vec[i]);
        }
        for(int i = mid+1; i <= right; i++){
            right_vec.push_back(vec[i]);
        }
        int i = 0, j = 0, k = left, l = left_vec.size(), r = right_vec.size();
        while(i<l && j<r){
            if(left_vec[i]<=right_vec[j]){
                vec[k] = left_vec[i];
                k++, i++;
            }else{
                vec[k] = right_vec[j];
                ans += l-i;
                k++, j++;
            }
        }
        while(i<l){
            vec[k] = left_vec[i];
            i++, k++;
        }
        while(j<r){
            vec[k] = right_vec[j];
            j++, k++;
        }
        return ans;
    }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int ans = 0, n = arr.size();
        ans = countInv(arr, 0, n-1);
        return ans;
    }
};