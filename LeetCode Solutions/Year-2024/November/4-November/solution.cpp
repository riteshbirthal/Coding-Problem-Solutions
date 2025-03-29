class Solution {
public:
    string compressedString(string word) {
        int n = word.size(), counter = 0;
        string comp = "";
        char c;
        for(int i = 0; i < n; i++){
            counter = 1;
            c = word[i];
            i++;
            while(i<n && counter<9 && word[i]==c){
                counter++, i++;
            }
            comp += to_string(counter) + c;
            i--;
        }
        return comp;
    }
};