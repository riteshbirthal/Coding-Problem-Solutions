class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int ans = 0, n = colors.size(), flag = 0;
            for(int i = 0; i < n; i++){
                if(flag && colors[(i+k-1)%n]!=colors[(i+k-2)%n])
                    ans++;
                else if(flag && colors[(i+k-1)%n]==colors[(i+k-2)%n])
                    flag = 0, i += k-2;
                else{
                    flag = 1;
                    for(int j = i+1; j < i+k; j++){
                        if(colors[j%n]==colors[(j-1)%n]) flag = 0;
                    }
                    if(flag) ans++;
                }
            }
            return ans;
        }
    };