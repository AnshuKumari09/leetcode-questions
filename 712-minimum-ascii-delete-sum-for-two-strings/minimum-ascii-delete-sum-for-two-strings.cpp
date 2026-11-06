
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
            return dp[i][j] = (int)word1[i] +
                solve(i+1, j+1, word1, word2, dp);
        }

        return dp[i][j] = max(
            solve(i+1, j, word1, word2, dp),
            solve(i, j+1, word1, word2, dp)
        );
    }

    int minimumDeleteSum(string s1, string s2) {

        int len1 = s1.length();
        int len2 = s2.length();

        vector<vector<int>> dp(
            len1, vector<int>(len2, -1)
        );

        int common = solve(0, 0, s1, s2, dp);

        int t1 = 0, t2 = 0;

        for(char ch : s1) {
            t1 += (int)ch;
        }

        for(char ch : s2) {
            t2 += (int)ch;
        }

        return t1 + t2 - 2 * common;
    }
};
