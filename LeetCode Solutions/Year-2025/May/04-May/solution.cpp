class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        map<pair<int, int>, int> u;
        for(auto d : dominoes){
            if(d[0]==d[1]){
                res += u.find({d[0], d[1]})==u.end() ? 0 : u[{d[0], d[1]}];
            }else{
                res += u.find({d[0], d[1]})==u.end() ? 0 : u[{d[0], d[1]}];
                res += u.find({d[1], d[0]})==u.end() ? 0 : u[{d[1], d[0]}];
            }
            u.find({d[0], d[1]})==u.end() ? u[{d[0], d[1]}] = 1 : u[{d[0], d[1]}]++;
        }
        return res;
    }
};