class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = 0, left = 0, right = letters.size()-1, mid;
        while(left<=right){
            mid = (left + right) / 2;
            if(letters[mid]>target)
                idx = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        return letters[idx];
    }
};
