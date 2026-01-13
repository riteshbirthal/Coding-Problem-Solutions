class Solution {
public:
    vector<long long> sepArea(vector<vector<int>>& squares, long long mid){
        vector<long long> areas(2, 0); // lower_area, upper_area
        long long x, y, l;
        int n = squares.size();
        for(int i = 0; i < n; i++){
            x = squares[i][0], y = squares[i][1], l = squares[i][2];
            if(y+l <= mid)
                areas[0] += l*l;
            else if(mid <= y)
                areas[1] += l*l;
            else
                areas[0] += l*(mid-y), areas[1] += l*(y+l-mid);
        }
        return areas;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double res = 0;
        long long left = 0, right = 2e9, mid, point = 0, lower_area, upper_area, current_area = 0;
        vector<long long> areas;
        while(left<=right){
            mid = (left + right) / 2;
            areas = sepArea(squares, mid);
            lower_area = areas[0], upper_area = areas[1];
            if(lower_area == upper_area)
                point = mid, right = mid-1;
            else if(lower_area > upper_area)
                point = mid-1, right = mid - 1;
            else
                left = mid + 1;
        }
        areas = sepArea(squares, point);
        lower_area = areas[0], upper_area = areas[1];
        if(areas[0]==areas[1])
            return point;
        int n = squares.size(), x, y, l;
        for(int i = 0; i < n; i++){
            x = squares[i][0], y = squares[i][1], l = squares[i][2];
            if(y<=point && point<y+l)
                current_area += l;
        }
        upper_area -= current_area;
        if(upper_area < lower_area)
            res = point + ((double(current_area - abs(upper_area - lower_area))) / double(2*current_area));
        else
            res = point + ((double(current_area + abs(upper_area - lower_area))) / double(2*current_area));
        return res;
    }
};
