class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        }
    };
    
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> freq;
        multiset<pair<int,int>, cmp> top, bottom;
        long long sumTop = 0;
        vector<long long> ans;

        auto add = [&](int num) {
            int f = freq[num];
            if (f > 0) {
                pair<int,int> old = {f, num};
                if (top.count(old)) {
                    top.erase(top.find(old));
                    sumTop -= 1LL * f * num;
                } else bottom.erase(bottom.find(old));
            }
            freq[num]++;
            pair<int,int> nw = {freq[num], num};
            bottom.insert(nw);
        };

        auto erase = [&](int num) {
            int f = freq[num];
            pair<int,int> old = {f, num};
            if (top.count(old)) {
                top.erase(top.find(old));
                sumTop -= 1LL * f * num;
            } else bottom.erase(bottom.find(old));
            freq[num]--;
            if (freq[num] > 0) bottom.insert({freq[num], num});
        };

        auto balance = [&]() {
            while ((int)top.size() < x && !bottom.empty()) {
                auto it = prev(bottom.end());
                sumTop += 1LL * it->first * it->second;
                top.insert(*it);
                bottom.erase(it);
            }
            while ((int)top.size() > x) {
                auto it = top.begin();
                sumTop -= 1LL * it->first * it->second;
                bottom.insert(*it);
                top.erase(it);
            }
            if (top.empty() || bottom.empty()) return;
            while (!top.empty() && !bottom.empty()) {
                auto itTop = top.begin();
                auto itBot = prev(bottom.end());
                if (*itBot <= *itTop) break;
                sumTop -= 1LL * itTop->first * itTop->second;
                sumTop += 1LL * itBot->first * itBot->second;
                bottom.insert(*itTop);
                top.insert(*itBot);
                bottom.erase(itBot);
                top.erase(itTop);
            }
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= k) erase(nums[i - k]);
            balance();
            if (i >= k - 1) ans.push_back(sumTop);
        }
        return ans;
    }
};
