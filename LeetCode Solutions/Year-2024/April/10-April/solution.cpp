class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        reverse(deck.begin(), deck.end());
        vector<int> vec;
        for(int i = 0; i < n; i++){
            if(vec.size()==0){
                vec.push_back(deck[i]);
            }else{
                vec.insert(vec.begin(), vec[vec.size()-1]);
                vec.pop_back();
                vec.insert(vec.begin(), deck[i]);
            }
        }
        return vec;
    }
};