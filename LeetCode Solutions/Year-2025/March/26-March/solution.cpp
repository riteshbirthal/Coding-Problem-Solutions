class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> vec;
            for(auto v : grid)
                for(int x : v)
                    vec.push_back(x);
            sort(vec.begin(), vec.end());
            int isPossible = 1, total = 0, left = 0, right = vec.size()-1;
            while(left<=right){
                isPossible = isPossible && (vec[left]%x == vec[right]%x) && (vec[left]%x == vec[0]%x);
                total += vec[right] - vec[left];
                left++, right--;
            }
    
            return isPossible ? total/x : -1;
        }
    };