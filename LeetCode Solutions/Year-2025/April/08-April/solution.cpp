class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        unordered_map<int, int> u;
        for(int x : nums)
            u.find(x)==u.end() ? u[x] = 1 : u[x]++;
        for(int x : nums){
            if(u.size()==n-res)
                return res%3==0 ? res/3 : res/3+1;
            u[x]==1 ? u.erase(x) : u[x]--;
            res += 1;
        }
        return res%3==0 ? res/3 : res/3+1;
    }
};
