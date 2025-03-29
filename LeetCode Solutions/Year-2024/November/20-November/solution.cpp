class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), a = 0, b = 0, c = 0, ans = 0, left = 1, right = n, mid, flag, temp_a, temp_b, temp_c;
        for(char ch : s){
            ch=='a' ? a++ : (ch=='b' ? b++ : c++);
        }
        if(a<k || b<k || c<k) return -1;
        while(left<=right){
            mid = (left + right) / 2;
            temp_a = 0, temp_b = 0, temp_c = 0, flag = 0;
            for(int i = 0; i < mid-1; i++){
                s[i]=='a' ? temp_a++ : (s[i]=='b' ? temp_b++ : temp_c++);
            }
            for(int i = mid-1; i < n && !flag; i++){
                s[i]=='a' ? temp_a++ : (s[i]=='b' ? temp_b++ : temp_c++);
                if(a-temp_a>=k && b-temp_b>=k && c-temp_c>=k) flag = 1;
                s[i-mid+1]=='a' ? temp_a-- : (s[i-mid+1]=='b' ? temp_b-- : temp_c--);
            }
            if(flag) ans = max(ans, mid), left = mid + 1;
            else right = mid - 1;
        }
        return n-ans;
    }
};