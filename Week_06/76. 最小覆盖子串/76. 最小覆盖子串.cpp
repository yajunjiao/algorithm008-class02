class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        // ��¼��С�����Ӵ�����ʼ����������
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            // c �ǽ����봰�ڵ��ַ�
            char c = s[right];
            // ���ƴ���
            right++;
            // ���д��������ݵ�һϵ�и���
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // �ж���ര���Ƿ�Ҫ����
            while (valid == need.size()) {
                // �����������С�����Ӵ�
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d �ǽ��Ƴ����ڵ��ַ�
                char d = s[left];
                // ���ƴ���
                left++;
                // ���д��������ݵ�һϵ�и���
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }                    
            }
        }
        // ������С�����Ӵ�
        return len == INT_MAX ?
            "" : s.substr(start, len);
    }
};