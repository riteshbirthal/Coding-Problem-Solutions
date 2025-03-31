class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size(), five = 0, ten = 0;
        for(int i = 0; i < n; i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10) five--, ten++;
            else{
                if(ten==0) five -= 3;
                else five--, ten--;
            }
            if(five<0 || ten<0) return false;
        }
        return true;
    }
};