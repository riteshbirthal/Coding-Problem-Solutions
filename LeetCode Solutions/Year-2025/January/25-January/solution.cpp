class Solution {
    public:
        vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
            vector<int> vec = nums, res;
            sort(vec.begin(), vec.end());
            map<int, queue<int>> mp;
            map<int, int> parent;
            mp[vec[0]].push(vec[0]);
            int n = vec.size(), current_parent = vec[0];
            parent[vec[0]] = vec[0];
            for(int i = 1; i < n; i++){
                if(vec[i]-vec[i-1]>limit){
                    current_parent = vec[i];
                }
                mp[current_parent].push(vec[i]);
                parent[vec[i]] = current_parent;
            }
            for(int i = 0; i < n; i++){
                res.push_back(mp[parent[nums[i]]].front());
                mp[parent[nums[i]]].pop();
            }
            return res;
        }
    };