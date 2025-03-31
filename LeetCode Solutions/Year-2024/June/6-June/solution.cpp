class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp, temp;
        for (int i = 0; i < hand.size(); i++) {
            if (mp.find(hand[i]) == mp.end())
                mp[hand[i]] = 1;
            else
                mp[hand[i]]++;
        }
        // for (auto x = mp.begin(); x != mp.end(); x++)
        //     cout << x->first << " " << x->second << endl;
        int pre, flag;
        while (mp.size()) {
            auto x = mp.begin();
            flag = 0, pre = -1;
            for (int i = 0; i < groupSize; i++, x++) {
                cout << x->first << endl;
                if (x == mp.end())
                    flag = 1;
                else if (pre == -1)
                    pre = x->first;
                else {
                    if (x->first != pre + 1)
                        flag = 1;
                    else
                        pre = x->first;
                }
            }
            if(flag) return false;
            else{
                for(int i = 0; i < groupSize; i++){
                    x = mp.begin();
                    if(x->second-1) temp[x->first] = x->second - 1;
                    mp.erase(x->first);
                }
                for(auto t = temp.begin(); t != temp.end(); t++){
                    mp[t->first] = t->second;
                }
                temp.clear();
            }
        }
        return true;
    }
};