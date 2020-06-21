//解法一：
class Solution {
public:
	string toLowerCase(string str) {
		int changeNum = 'a' - 'A';
		for(int i = 0; i < str.size(); ++i) {
			str[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + changeNum : str[i];
		}
		return str;
	}
};

//解法二：
class Solution {
public:
	string toLowerCase(string str) {
		string ans;
        for(char s : str) {
			s |= 32;
            ans += s;
		}
        ans[str.size()] = '\0';
		return ans;
	}
};

