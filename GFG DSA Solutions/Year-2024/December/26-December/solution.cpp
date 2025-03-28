// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int, int> u;
        for(int x : arr){
            if(u.find(x)==u.end()) u[x] = 1;
            else u[x]++;
        }
        for(int x : arr){
            if(u.find(target-x)!=u.end()){
                if(2*x==target && u[x]>1) return true;
                else if(2*x!=target) return true;
            }
        }
        return false;
    }
};