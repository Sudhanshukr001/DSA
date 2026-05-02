// class Solution {
// public:
//     int rotatedDigits(int n) {
//         int q = n / 10;
//         int count = 0;

//         vector<vector<char>> arr(q + 1, vector<char>(10));

//         // Base case: single digits
//         for (int i = 0; i < 10; i++) {
//             if (i == 0 || i == 1 || i == 8) {
//                 arr[0][i] = 'u';
//             } else if (i == 2 || i == 5 || i == 6 || i == 9) {
//                 arr[0][i] = 'v';
//                 count++;
//             } else {
//                 arr[0][i] = 'i';
//             }
//             if (i == n) return count;
//         }

//         // Build for 2-digit numbers
//         for (int i = 1; i <= q; i++) {
//             for (int j = 0; j < 10; j++) {
//                 int num = i * 10 + j;
//                 if (num > n) break;

//                 int prefixState;
//                 if (i < 10) {
//                     prefixState = arr[0][i];  // single digit prefix
//                 } else {
//                     prefixState = arr[i / 10][i % 10];  // correct lookup
//                 }

//                 if (prefixState == 'i' || arr[0][j] == 'i') {
//                     arr[i][j] = 'i';
//                 } else if (prefixState == 'u' && arr[0][j] == 'u') {
//                     arr[i][j] = 'u';
//                 } else {
//                     arr[i][j] = 'v';
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };



class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;

        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8)
                    dp[i] = 1; // valid but same
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2; // valid and different
                    count++;
                }
            } else {
                int a = dp[i / 10];
                int b = dp[i % 10];

                if (a == 1 && b == 1)
                    dp[i] = 1;
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    count++;
                }
            }
        }

        return count;
    }
};