class Solution {
public:
    int hammingWeight(uint32_t n) {
        int m = 0;
        for(; n; ++m) {
            n &= n - 1;
        }
        return m;
    }
};