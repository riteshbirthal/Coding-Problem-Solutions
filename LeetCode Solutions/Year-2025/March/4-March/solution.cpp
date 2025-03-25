class Solution {
    public:
        bool func(int n, vector<int>& powers, int idx){
            if(idx==powers.size())
                return n==0;
            if(powers[idx]==n)
                return true;
            if(powers[idx]>n)
                return false;
            return func(n-powers[idx], powers, idx+1) || func(n, powers, idx+1);
        }
        
        bool checkPowersOfThree(int n) {
            if(n%3==2)
                return false;
            vector<int> powers;
            for(int i = 0; pow(3, i) <= n; i++){
                powers.push_back((int)pow(3, i));
            }
            return func(n, powers, 0);
        }
    };