class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        //return isAnagramFirst(s, t);
        return isAnagramSecond(s, t);
    }

    bool isAnagramFirst(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t ? true : false;
    }

    bool isAnagramSecond(string s, string t) {
        int hash[26] = {0};
        for(auto n : s) {
            hash[n - 'a']++;
        }
        for(auto o : t) {
            hash[o - 'a']--;
            if(hash[o - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};