class Solution {
    public:
        bool checkIfExist(vector<int>& arr) {
            unordered_set<int> u;
            for(int x : arr){
                if(u.find(2*x)!=u.end()) return true;
                if(x%2==0 && u.find(x/2)!=u.end()) return true;
                u.insert(x);
            }
            return false;
        }
    };