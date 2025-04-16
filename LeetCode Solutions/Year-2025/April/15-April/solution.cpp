class FenwickTree {
private:
    vector<long long> tree;
    int n;
public:
    FenwickTree(int size) : n(size) {
        tree.assign(n + 1, 0);
    }
    void update(int index, long long value) {
        index++;
        while (index <= n) {
            tree[index] += value;
            index += index & -index;
        }
    }
    long long query(int index) {
        index++;
        long long sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> index_in_nums2;
        for (int j = 0; j < n; j++) {
            index_in_nums2[nums2[j]] = j;
        }
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[i] = index_in_nums2[nums1[i]];
        }
        FenwickTree ft_left(n);
        vector<long long> left(n, 0);
        for (int j = 0; j < n; j++) {
            left[j] = ft_left.query(pos[j] - 1);
            ft_left.update(pos[j], 1);
        }
        FenwickTree ft_right(n);
        vector<long long> right(n, 0);
        for (int j = n - 1; j >= 0; j--) {
            right[j] = ft_right.query(n - 1) - ft_right.query(pos[j]);
            ft_right.update(pos[j], 1);                                
        }
        long long res = 0;
        for (int j = 0; j < n; j++) {
            res += left[j] * right[j];
        }
        return res;
    }
};