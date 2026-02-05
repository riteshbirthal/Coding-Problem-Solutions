class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        set<pair<int, pair<int, int>>> st; // {element, {idx, array}} => array ==> a:0   b:1   c:2
        int min_diff = INT_MAX, min_sum = INT_MAX, n = a.size();
        st.insert({a[0], {1, 0}});
        st.insert({b[0], {1, 1}});
        st.insert({c[0], {1, 2}});
        pair<int, pair<int, int>> pr, pr1, pr2;
        vector<int> res(3);
        while(st.size()==3){
            pr = *st.begin();
            st.erase(pr);
            auto itr = st.begin();
            pr1 = *itr;
            ++itr;
            pr2 = *itr;
            if((pr2.first-pr.first < min_diff) || (pr2.first-pr.first==min_diff && pr.first+pr1.first+pr2.first < min_sum)){
                res[2] = pr.first;
                res[1] = pr1.first;
                res[0] = pr2.first;
                min_sum = res[0] + res[1] + res[2];
                min_diff = pr2.first - pr.first;
            }
            if(pr.second.second==0 && pr.second.first<n){
                st.insert({a[pr.second.first], {pr.second.first+1, 0}});
            }else if(pr.second.second==1 && pr.second.first<n){
                st.insert({b[pr.second.first], {pr.second.first+1, 1}});
            }else if(pr.second.first<n){
                st.insert({c[pr.second.first], {pr.second.first+1, 2}});
            }
        }
        return res;
    }
};
