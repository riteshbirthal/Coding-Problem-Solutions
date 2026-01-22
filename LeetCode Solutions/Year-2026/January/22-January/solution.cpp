class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0, n, idx, min_sum;
        bool is_sorted;
        vector<int> curr = nums, next;
        while(true){
            n = curr.size();
            idx = -1, min_sum = INT_MAX, is_sorted = true;
            for(int i = 1; i < n; i++){
                if(curr[i]+curr[i-1]<min_sum)
                    idx = i, min_sum = curr[i] + curr[i-1];
                is_sorted = is_sorted && (curr[i-1]<=curr[i]);
            }
            if(is_sorted)
                break;
            for(int i = 0; i < n; i++){
                next.push_back(curr[i]);
                if(i==idx-1)
                    next[next.size()-1] += curr[i+1], i++;
            }
            curr = next;
            next.clear();
            res += 1;
        }
        return res;
    }
};
