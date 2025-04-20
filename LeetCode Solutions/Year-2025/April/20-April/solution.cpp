class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int res = 0;
            unordered_map<int, int> u;
            for(int x : answers)
                u.find(x)==u.end() ?  u[x] = 1 : u[x]++;
            for(auto x = u.begin(); x != u.end(); x++){
                while(x->second){
                    res += (x->first) + 1;
                    x->second -= min(x->second, (x->first + 1));
                }
            }
            return res;
        }
    };