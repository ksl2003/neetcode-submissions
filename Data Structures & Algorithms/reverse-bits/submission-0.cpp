class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 0;
        while(n){
            int digit = n%2;
            n = n>>1;
            if(digit) ans |= (1 << (31 - i));
            i++;
        }
        return ans;
    }
};
