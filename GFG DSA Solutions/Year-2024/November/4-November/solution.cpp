// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>> vec;
        vector<int> v;
        set<vector<int>> st;
        int n = arr.size(), left, right, mid, idx;
        for(int i = 0; i < n; i++){
            vec.push_back({arr[i], i});
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(vec[i][0]+vec[j][0]>0)
                    continue;
                left = j+1, right = n-1, idx = -1;
                while(left<=right){
                    mid = (left + right) / 2;
                    if(vec[i][0] + vec[j][0] + vec[mid][0]==0){
                        idx = mid;
                        break;
                    }else if(vec[i][0] + vec[j][0] + vec[mid][0]>0){
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                    }
                }
                if(idx==-1)
                    continue;
                for(int k = idx; k > j && vec[i][0]+vec[j][0]+vec[k][0]==0; k--){
                    v = {vec[i][1], vec[j][1], vec[k][1]};
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
                for(int k = idx+1; k < n && vec[i][0]+vec[j][0]+vec[k][0]==0; k++){
                    v = {vec[i][1], vec[j][1], vec[k][1]};
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};