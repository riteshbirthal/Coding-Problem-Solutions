class Solution {
    public:
        bool doesValidArrayExist(vector<int>& derived) {
            int current0 = 0, current1 = 1, n = derived.size();
            bool res = true;
            for(int i = 0; i < n; i++){
                current0 = current0^derived[i];
                current1 = current1^derived[i];
            }
            res = (current0==0) || (current1==1);
            return res;
        }
    };