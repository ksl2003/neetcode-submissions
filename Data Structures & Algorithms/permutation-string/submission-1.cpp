class Solution {
   private:
    bool findAllZero(vector<int> freqCh) {
        for (auto a : freqCh) {
            if (a != 0) {
                return false;
            }
        }
        return true;
    }

   public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        int start = 0, end = s1.length() - 1;
        vector<int> freqChS1(26, 0);
        vector<bool> charPres(26, false);
        int n1 = s1.length();
        for (auto a : s1) {
            int ch = (int)a - 'a';
            freqChS1[ch]++;
            charPres[ch] = true;
        }

        int n2 = s2.length();
        for (int i = start; i <= end; i++) {
            int presCh = (int)s2[i] - 'a';
            if (charPres[presCh]) {
                freqChS1[presCh]--;
            }
        }
        while (end < n2 && n1) {
            if (findAllZero(freqChS1)) {
                return true;
            }
            start++;
            end++;
            if (end < n2) {
                int presCh = (int)s2[start-1] - 'a';
                if (charPres[presCh]) {
                    freqChS1[presCh]++;
                }
                int presCh2 = (int)s2[end] - 'a';
                if (charPres[presCh2]) {
                    freqChS1[presCh2]--;
                }
            }
        }
        return false;
    }
};
