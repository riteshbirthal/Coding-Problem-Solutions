
class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        char ch = '$';
        unordered_map<int, int> u;
        for(char c : s){
            u.find(c)==u.end() ? u[c] = 1 : u[c]++;
        }
        for(char c : s){
            if(u[c]==1){
                ch = c;
                break;
            }
        }
        return ch;
    }
};