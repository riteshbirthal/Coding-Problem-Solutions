class Solution {
    public:
        static bool sortByX(vector<int>& a, vector<int>& b){
            if(a[0]==b[0])
                return a[2]<b[2];
            return a[0]<b[0];
        }
    
        static bool sortByY(vector<int>& a, vector<int>& b){
            if(a[1]==b[1])
                return a[3]<b[3];
            return a[1]<b[1];
        }
    
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            int siz = rectangles.size(), count = 0, mx;
            sort(rectangles.begin(), rectangles.end(), sortByX);
            for(int i = 1; i < siz; i++){
                mx  = max(mx, rectangles[i-1][2]);
                if(mx<=rectangles[i][0])
                    count++;
            }
            if(count>1)
                return true;
            sort(rectangles.begin(), rectangles.end(), sortByY);
            count = 0, mx = 0;
            for(int i = 1; i < siz; i++){
                mx = max(mx, rectangles[i-1][3]);
                if(mx<=rectangles[i][1])
                    count++;
            }
            return count>1;;
        }
    };