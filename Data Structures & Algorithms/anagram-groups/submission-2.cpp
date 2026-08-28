class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for (auto a : strs) {
            vector<int> freq(26, 0);

            for (auto b : a) {
                freq[b - 'a']++;
            }

            mp[freq].push_back(a);
        }

        vector<vector<string>> ans;

        for (auto [key, val] : mp) {
            ans.push_back(val);
        }

        return ans;
    }
};