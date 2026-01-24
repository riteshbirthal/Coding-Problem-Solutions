class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0, boxes = 0;
        for (int x : apple)
            apples += x;
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());
        for (int x : capacity)
            if (apples <= 0)
                break;
            else
                apples -= x, boxes++;
        return boxes;
    }
};
