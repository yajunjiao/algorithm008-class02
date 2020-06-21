//�ⷨһ��
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

//1.���������������ʯͷ�Ƿ��Ǳ�ʯ

//�ⷨ2
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

//�򵥵Ĺ�ϣ���洢����ֵ��
