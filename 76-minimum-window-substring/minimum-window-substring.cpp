class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqs(256, 0);
        vector<int> freqt(256, 0);

        for (int i = 0; i < t.size(); i++) {
            freqt[t[i]]++;
        }

        int ft = 0, st = 0, count = 0;
        int mini = INT_MAX, start = 0;

        while (st < s.size()) {

            // include current character
            freqs[s[st]]++;
            if (freqs[s[st]] <= freqt[s[st]]) {
                count++;
            }

            // try to shrink window
            while (count == t.size()) {
                if (st - ft + 1 < mini) {
                    mini = st - ft + 1;
                    start = ft;
                }

                freqs[s[ft]]--;
                if (freqs[s[ft]] < freqt[s[ft]]) {
                    count--;
                }
                ft++;
            }

            st++;
        }

        if (mini == INT_MAX) return "";
        return s.substr(start, mini);
    }
};