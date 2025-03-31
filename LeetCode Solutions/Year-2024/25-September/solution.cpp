class Solution {
public:
    struct Node {
        int count;
        Node* vec[26];
        Node(): count(0) {
            for(int i = 0; i < 26; i++)
                vec[i] = NULL;
        }
    };

    Node* insertElement(Node* & node, string & st, int n){
        if(!node) node = new Node();
        node->count += 1;
        if(n==st.size()-1){
            return node;
        }
        node->vec[st[n+1]-'a'] = insertElement(node->vec[st[n+1]-'a'], st, n+1);
        return node;
    }

    int findPrefix(Node* & node, string & st, int n){
        if(n==st.size()-1) return node->count;
        if(node->count == 1)
            return st.size()-n;
        return node->count + findPrefix(node->vec[st[n+1]-'a'], st, n+1);
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<Node*> Trie(26, NULL);
        vector<int> vec;
        for(auto s : words){
            Trie[s[0]-'a'] = insertElement(Trie[s[0]-'a'], s, 0);
        }
        for(auto s : words){
            vec.push_back(findPrefix(Trie[s[0]-'a'], s, 0));
        }
        return vec;
    }
};