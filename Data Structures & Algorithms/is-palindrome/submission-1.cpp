class Solution {
   private:
    bool isAlphaNumeric(char ch) {
        // Checks if 'ch' is a lowercase letter OR a digit
        return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }

   public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
        while (i < j) {
            char frChar = s[i];
            char baChar = s[j];

            if (isAlphaNumeric(frChar) && isAlphaNumeric(baChar)) {
                if (frChar != baChar) {
                    return false;
                }
                i++;
                j--;
            }

            else if (frChar < 'a' || frChar > 'z') {
                i++;
            } else {
                j--;
            }
        }
        return true;
    }
};
