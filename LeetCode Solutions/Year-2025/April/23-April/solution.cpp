class Solution {
public:
    int countLargestGroup(int n) {
        int res = 0, digitSum, mxGroupSize = 0;
        unordered_map<int, int> u;
        for(int i = 1; i <= n; i++){
            digitSum = 0;
            for(int j = i; j; j /= 10)
                digitSum += j%10;
            u.find(digitSum)==u.end() ? u[digitSum] = 1 : u[digitSum]++;
            mxGroupSize = max(mxGroupSize, u[digitSum]);
        }
        for(auto x = u.begin(); x != u.end(); x++)
            res += x->second==mxGroupSize;
        return res;
    }
};