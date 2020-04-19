class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int cur = digits.size() - 1; cur >= 0; cur--) {
            digits[cur]++;
            if(10 != digits[cur]) {
                return digits;
            } else {
                digits[cur] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};