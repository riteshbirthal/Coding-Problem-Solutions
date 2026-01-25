class Solution {
public:
    int bestClosingTime(string customers) {
        int left = 0, right = 0;
        for(char & c : customers)
            right += c=='Y';
        int res = 0, min_penalty = right, idx = 0;
        for(char &c : customers){
            if(left + right < min_penalty)
                res = idx, min_penalty = left + right;
            left += c=='N';
            right -= c=='Y';
            idx += 1;
        }
        if(left + right < min_penalty)
            res = idx, min_penalty = left + right;
        return res;
    }
};
