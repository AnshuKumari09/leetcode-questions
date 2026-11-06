// class Solution {
// public:
//     int solve(int i,int j,string word1, string word2){
//             if(i==word1.length() || j==word2.length()){
//                 return 0;
//             }
//             if(word1[i]==word2[j]){     
//                 return 1+solve(i+1,j+1,word1,word2);
//             }
//             return max({solve(i+1,j,word1,word2),solve(i,j+1,word1,word2)});

//     }
//     int minDistance(string word1, string word2) {
//         if(word1.length()==0){
//             return word2.length();
//         }
//         if(word1.length()==0){
//             return word2.length();
//         }
//         int common=solve(0,0,word1,word2);
//         int len1=word1.length();
//         int len2=word2.length();
//         return (len1+len2-2*common);
//     }
// };



class Solution {
public:
    int solve(int i, int j, string &word1, string &word2,
              vector<vector<int>>& dp) {

        if(i == word1.length() || j == word2.length()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(word1[i] == word2[j]) {
            return dp[i][j] = 1 + solve(i+1, j+1, word1, word2, dp);
        }

        return dp[i][j] = max(
            solve(i+1, j, word1, word2, dp),
            solve(i, j+1, word1, word2, dp)
        );
    }

    int minDistance(string word1, string word2) {

        int len1 = word1.length();
        int len2 = word2.length();

        vector<vector<int>> dp(len1, vector<int>(len2, -1));

        int common = solve(0, 0, word1, word2, dp);

        return len1 + len2 - 2 * common;
    }
};
