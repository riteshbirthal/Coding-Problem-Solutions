class Solution {
    public:
        bool isValid(vector<int>& a, vector<int>& b){
            return b[0]>a[0] && b[1]>a[1] && b[2]>a[2];
        }
    
        int numberOfSubstrings(string s) {
            int res = 0, total, n = s.size(), h_idx, left, right, mid;
            vector<vector<int>> vec(n+1, {0, 0, 0});
            bool flag;
            for(int i = 0; i < n; i++){
                vec[i+1] = vec[i];
                vec[i+1][s[i]-'a']++;
                if(i<2)
                    continue;
                h_idx = -1;
                left = 0, right = i;
                while(left<=right){
                    mid = (left + right) / 2;
                    flag = isValid(vec[mid], vec[i+1]);
                    if(flag){
                        h_idx = mid;
                        left = mid + 1;
                    }else{
                        right = mid - 1;
                    }
                }
                res += h_idx + 1;
            }
            return res;
        }
    };