class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>ansAlpha(26,0);
        for(int i =0; i< sentence.size(); i++){
            ansAlpha[sentence[i]-'a'] = 1;
        }
        for(int i =0; i<ansAlpha.size(); i++){
            if(ansAlpha[i]==0){
                return 0;
            }
        }
        return 1;
    }
};