//解法一：
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int ans = 0;
        for(char c : S) {
            for(char j : J) {
                ans = c == j ? ans + 1 : ans;
            }
        }
        return ans;
	}
};

//1.暴力法，求出所有石头是否是宝石

//解法2
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int ans = 0;
		unordered_map<char, int> mp;
		for(char c : J) {
			mp[c] = 1;
		}
		for(char c : S) {
			if(mp[c]) {
				ans++;
			}
		}
		return ans;
	}
};

//简单的哈希表，存储所有值。
