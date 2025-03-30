/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size(), res = -1, total = 0, isPossible;
        vector<int> vec;
        for(int i = 0; i < n; i++){
            vec.push_back(gas[i]-cost[i]);
        }
        for(int i = 0; i < n; i++){
            if(vec[i]<0)
                continue;
            total = 0, isPossible = 0;
            for(int j = i; j < i+n && total>=0; j++){
                total += vec[j%n];
                if(j==i+n-1 && total>=0)
                    isPossible = 1;
                if(total<0)
                    i = j;
            }
            if(isPossible)
                return i;
        }
        return res;
    }
};

