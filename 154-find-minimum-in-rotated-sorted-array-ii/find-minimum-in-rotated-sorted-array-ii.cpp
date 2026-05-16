class Solution {
public:
    int findMin(vector<int>& array) {
    int n  = array.size();
    int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(array[i],mini);

        }
        return mini;
    }
    
};