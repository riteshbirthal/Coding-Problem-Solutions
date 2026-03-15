class Solution {
public:
    int bitwiseComplement(int n) {
        string b = "", updated = "";
        if(!n) b = "0";
        while (n)
            b += '0' + n % 2, n /= 2;
        reverse(b.begin(), b.end());
        for (char c : b)
            updated += c == '0' ? '1' : '0';
        return stoi(updated, 0, 2);
    }
};
