class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int x : nums)
            res += to_string(x).size()%2==0;
        return res;
    }
};
