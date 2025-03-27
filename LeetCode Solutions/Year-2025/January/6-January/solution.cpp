class Solution {
    public:
        vector<int> minOperations(string boxes) {
            int n = boxes.size(), countLeft = 0, countRight = 0;
            vector<int> res, left(n+1, 0), right(n+1, 0);
            for(int i = 0; i < n; i++){
                left[i+1] = left[i] + countLeft;
                right[n-1-i] = right[n-i] + countRight;
                countLeft += int(boxes[i]=='1');
                countRight += int(boxes[n-1-i]=='1');
            }
            for(int i = 0; i < n; i++){
                res.push_back(left[i+1]+right[i]);
            }
            return res;
        }
    };