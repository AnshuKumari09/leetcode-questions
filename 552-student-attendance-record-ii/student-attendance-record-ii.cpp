
class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int n, int abs, int consecLate,
              vector<vector<vector<int>>>& dp) {

        if (abs > 1 || consecLate >= 3) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        if (dp[n][abs][consecLate] != -1) {
            return dp[n][abs][consecLate];
        }

        int p = solve(n - 1, abs, 0, dp);
        int ab = solve(n - 1, abs + 1, 0, dp);
        int CLate = solve(n - 1, abs, consecLate + 1, dp);

        return dp[n][abs][consecLate] =
            ((p + ab) % mod + CLate) % mod;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(n, 0, 0, dp);
    }
};
