class Solution {
public:
    void getPrimes(vector<int>& primes){
        bool isPrime;
        for(int i = 2; i < 1000; i++){
            isPrime = true;
            for(int j = 2; j < int(sqrt(i))+1 && isPrime; j++){
                if(i%j==0) isPrime = false;
            }
            if(isPrime) primes.push_back(i);
        }
        return ;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        getPrimes(primes);
        int n = nums.size(), p = primes.size();
        for(int i = n-2; i > -1; i--){
            if(nums[i+1]<=nums[i]){
                for(int j = 0; j < p && primes[j]<nums[i]; j++){
                    if(nums[i+1]>nums[i]-primes[j]){
                        nums[i] -= primes[j];
                        break;
                    }
                }
            }
            if(nums[i+1]<=nums[i]) return false;
        }
        return true;
    }
};