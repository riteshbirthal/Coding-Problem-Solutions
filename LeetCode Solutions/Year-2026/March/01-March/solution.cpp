class Solution {
public:
    int minPartitions(string n) {
        int res = *max_element(n.begin(), n.end()) - '0';
        return res;
    }
};
