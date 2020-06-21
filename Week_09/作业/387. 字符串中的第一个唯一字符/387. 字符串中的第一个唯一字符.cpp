class Solution {
public:
	int firstUniqChar(string s) {
		int hash[26] = {0}��
		for(char ch : s) {
			hash[ch - 'a']++;
		}
		for(int i = 0; i < s.size(); ++i) {
			if(hash[ch - s[i]] == 1)
				return i;
		}
		return -1;
	}
};