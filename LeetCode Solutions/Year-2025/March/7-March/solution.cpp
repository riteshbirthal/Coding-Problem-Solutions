class Solution {
    public:
        bool checkPrime(int n){
            if(n==1)
                return false;
            if(n<4)
                return true;
            bool res = true;
            for(int i = 2; i <= sqrt(n); i++)
                res = res && (!(n%i==0));
            return res;
        }
    
        vector<int> closestPrimes(int left, int right) {
            vector<int> vec, res = {-1, -1};
            int diff = INT_MAX, n;
            for(int i = left; i <= right; i++){
                if(checkPrime(i))
                    vec.push_back(i);
                n = vec.size();
                if(n>1){
                    if(vec[n-1]-vec[n-2]<=2)
                        return {vec[n-2], vec[n-1]};
                    else if(vec[n-1]-vec[n-2]<diff){
                        diff = vec[n-1]-vec[n-2], res = {vec[n-2], vec[n-1]};
                    }
                }
            }
            return res;
        }
    };