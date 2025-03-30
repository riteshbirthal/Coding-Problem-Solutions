class Solution {
public:
    int maximumSwap(int num) {
        string original = to_string(num), sorted = original;
        sort(sorted.begin(), sorted.end());
        reverse(sorted.begin(), sorted.end());
        int n = original.size(), flag = 1;
        for(int i = 0; i < n && flag; i++){
            if(original[i]!=sorted[i]){
                char mx = original[i];
                int idx = i;
                for(int j = i+1; j < n; j++){
                    if(mx<=original[j])
                        mx = original[j], idx = j;
                }
                original[idx] = original[i];
                original[i] = mx;
                flag = 0;
            }
        }
        return stoi(original);
    }
};