class Solution {
public:
    int countBits(int n){
        int res = 0;
        while(n)
            res += n&1, n /= 2;
        return res;
    }

    int countPrimeSetBits(int left, int right) {
        int res = 0;
        set<int> st;
        st.insert(2); st.insert(3); st.insert(5); st.insert(7); st.insert(11); st.insert(13); st.insert(17); st.insert(19); st.insert(23);
        for(int i = left; i <= right; i++)
            res += st.find(countBits(i))!=st.end() ? 1 : 0;
        return res;
    }
};
