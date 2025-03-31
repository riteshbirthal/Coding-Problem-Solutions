class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0, n1 = arr1.size(), n2 = arr2.size(), temp, count;
        unordered_set<int> u_set;
        for(int i = 0; i < n1; i++){
            temp = arr1[i];
            while(temp){
                u_set.insert(temp);
                temp /= 10;
            }
        }
        for(int i = 0; i < n2; i++){
            temp = arr2[i], count = 0;
            while(temp){
                if(u_set.find(temp)!=u_set.end() || count){
                    count++;
                }
                temp /= 10;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};