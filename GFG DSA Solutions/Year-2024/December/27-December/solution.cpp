class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int, int> u;
        int ans = 0;
        for(int x : arr){
            if(u.find(x)==u.end()) u[x] = 1;
            else u[x] += 1;
        }
        for(auto x = u.begin(); x != u.end(); x++){
            if(2 * x->first == target){
                ans += x->second * (x->second - 1);
            }else{
                if(u.find(target - x->first) != u.end()){
                    ans += (x->second * u[target - x->first]);
                }
            }
        }
        return ans/2;
    }
};