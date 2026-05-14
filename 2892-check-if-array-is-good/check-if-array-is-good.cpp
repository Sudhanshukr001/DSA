class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int ,int>map;
        for(auto i : nums){
            map[i]++;
        }
        int n = nums.size();
        for(int i = 1; i<n-1; i++){
            if(map[i]==1){

            }else{
                return false;
            }
        }
        if(map[n-1] != 2) return false;
        return true;
    }
};