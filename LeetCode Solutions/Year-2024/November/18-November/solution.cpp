class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> vec;
        int n = code.size(), sum, change, idx;
        for(int i = 0; i < n; i++){
            sum = 0;
            change = k<0 ? 1 : -1;
            idx = k;
            while(idx){
                sum += code[(i+idx+n)%n];
                idx += change;
            }
            vec.push_back(sum);
        }
        return vec;
    }
};