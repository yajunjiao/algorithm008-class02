//1.采用滑动窗口  
class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res; // 记录结果
        while (right < s.size()) {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) 
                    valid++;
            }
            // 判断左侧窗口是否要收缩
            while (right - left >= t.size()) {
                // 当窗口符合条件时，把起始索引加入 res
                if (valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
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
//2. 做缓存，然后去查找，返回合适的值。
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