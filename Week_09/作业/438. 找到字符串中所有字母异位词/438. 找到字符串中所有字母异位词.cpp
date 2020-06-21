//1.���û�������  
class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res; // ��¼���
        while (right < s.size()) {
            char c = s[right];
            right++;
            // ���д��������ݵ�һϵ�и���
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) 
                    valid++;
            }
            // �ж���ര���Ƿ�Ҫ����
            while (right - left >= t.size()) {
                // �����ڷ�������ʱ������ʼ�������� res
                if (valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;
                // ���д��������ݵ�һϵ�и���
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};
//2. �����棬Ȼ��ȥ���ң����غ��ʵ�ֵ��
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int l = p.length();
        vector<int> ans;
        vector<int> vp(26, 0);
        vector<int> vs(26, 0);
        for (char c : p) vp[c - 'a']++;
        for(int i = 0; i < n; i++){
            if(i >= l) vs[s[i-l] - 'a']--;
            vs[s[i] - 'a']++;
            if(vs == vp) ans.push_back(i + 1 - l);
        }
        return ans;
    }
};