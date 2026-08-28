class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> mp;
        for(auto a: nums){
            if(mp[a]==true){
                return true;
            }
            mp[a] = true;
        }
        return false;
    }
};