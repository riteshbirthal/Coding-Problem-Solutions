class Solution {
public:
    bool func(vector<vector<char>> &board, string word, int i, int j, int k, vector<vector<int>> &visit){
        if(k==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k] || visit[i][j]) return false;
        visit[i][j] = 1;
        if(func(board, word, i+1, j, k+1, visit)) return true;
        if(func(board, word, i-1, j, k+1, visit)) return true;
        if(func(board, word, i, j+1, k+1, visit)) return true;
        if(func(board, word, i, j-1, k+1, visit)) return true;
        visit[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        set<char> st;
        int n = board.size(), m = board[0].size();
        vector<vector<int>> st_vec;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                st.insert(board[i][j]);
                if(board[i][j]==word[0]) st_vec.push_back({i, j});
            }
        }
        for(int i = 0; i < word.size(); i++) if(st.find(word[i])==st.end()) return false;
        bool ans = false;
        for(int i = 0; i < st_vec.size(); i++){
            vector<vector<int>> visit(n, vector<int>(m, 0));
            ans = func(board, word, st_vec[i][0], st_vec[i][1], 0, visit);
            if(ans) return true;
        }
        return false;
    }
};