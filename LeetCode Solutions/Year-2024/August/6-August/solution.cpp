class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size(), ans = 0;
        vector<int> vec(26, 0);
        for(int i = 0; i < n; i++)
            vec[word[i]-'a']++;
        priority_queue<int> pq;
        for(int i = 0; i < 26; i++)
            if(vec[i])
                pq.push(vec[i]);
        for(int i = 1; i < 5 && !pq.empty(); i++){
            for(int j = 0; j < 8 && !pq.empty(); j++){
                ans += i * pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};