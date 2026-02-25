class Solution {
public:
    static bool custom_sort(int a, int b){
        int count1 = 0, count2 = 0, n1 = a, n2 = b;
        while(n1)
            count1 += n1&1, n1 /= 2;
        while(n2)
            count2 += n2&1, n2 /= 2;
        if(count1==count2)
            return a<b;
        return count1<count2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), custom_sort);
        return arr;
    }
};
