class Solution {
    void anticlockwise(string& s) {
        char ch = s[0];
        int idx = 1;
        while (idx < s.size()) {
            s[idx - 1] = s[idx];
            idx++;
        }
        s[s.size() - 1] = ch;
    }

public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size())
            return false;

        for (int i = 0; i < s.size(); i++){
                if (s == goal)
                    return true;
                anticlockwise(s);
            }
        return false;
    }
};