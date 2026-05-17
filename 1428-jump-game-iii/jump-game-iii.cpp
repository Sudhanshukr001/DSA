class Solution {
public:
    int n;

    bool game(vector<int>& arr, int i) {
        if (i < 0 || i >= n || arr[i] < 0)
            return false;

        if (arr[i] == 0)
            return true;

        int jump = arr[i];

        arr[i] *= -1; 

        bool left = game(arr, i - jump);
        bool right = game(arr, i + jump);

        return left || right;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();   
        return game(arr, start);
    }
};