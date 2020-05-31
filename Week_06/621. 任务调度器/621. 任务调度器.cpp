class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26,0);
        for(auto type : tasks)  // Ͱ����˼��
            cnt[type-'A']++;
        int cnt_max = 0, equal_cnt_max = -1;  // equal_cnt_max��ֵΪ-1����Ϊ�����ѭ�������һ��
        for(auto i: cnt) cnt_max = max(i, cnt_max);
        for(int i = 25; i>=0; --i) 
            if(cnt_max == cnt[i])
                ++equal_cnt_max;  // ͳ�Ƴ��ִ����������ִ�����ͬ�������ܸ���
        int ans = max((cnt_max-1)*n+cnt_max+equal_cnt_max, (int)tasks.size());
        return ans;
    }
};