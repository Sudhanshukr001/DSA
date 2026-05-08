class Solution {
public:
    int countPrimes(int n) {
        vector<bool>checkPrime(n+1,true);
        int count = 0;
        for(int i = 2; i<n; i++){
            if(checkPrime[i]){
                count++;
                for(int j = i*2; j<n; j = j + i){
                    checkPrime[j]=false;
                }
            }
        }
        return count;
    }
};