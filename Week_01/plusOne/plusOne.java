class Solution {
    public int[] plusOne(int[] digits) {
        for(int cur = digits.length - 1; cur >= 0; cur--) {
            digits[cur]++;
            if(digits[cur] != 10) {
                return digits;
            } else {
                digits[cur] = 0;
            }
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}