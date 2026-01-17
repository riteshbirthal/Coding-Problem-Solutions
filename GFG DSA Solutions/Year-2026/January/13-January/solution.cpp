class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        bool res = true;
        int count5 = 0, count10 = 0;
        for(int x : arr){
            if(x==5)
                count5++;
            else if(x==10)
                if(count5)
                    count5--, count10++;
                else
                    return false;
            else
                if(count10 && count5)
                    count10--, count5--;
                else if(count5>2)
                    count5 -= 3;
                else
                    return false;
        }
        return res;
    }
};
