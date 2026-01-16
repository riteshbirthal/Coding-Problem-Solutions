class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int res = 0, police = 0, thief = 0, n = arr.size();
        while(police < n && thief < n){
            while(police < n && arr[police]!='P')
                police++;
            while(thief < n && arr[thief]!='T')
                thief++;
            if(police < n && thief < n){
                if(abs(police - thief) <= k){
                    res++;
                    thief++, police++;
                }else{
                    thief < police ? thief++ : police++;
                }
            }
        }
        return res;
    }
};
