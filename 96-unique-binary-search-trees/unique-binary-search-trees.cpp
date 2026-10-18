
class Solution {
public:
    int t[20];

    int solve(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }

        if(t[n] != -1) {
            return t[n];
        }

        int total = 0;

        for(int root = 1; root <= n; root++) {

            int leftNodes = root - 1;
            int rightNodes = n - root;

            int leftWays = solve(leftNodes);
            int rightWays = solve(rightNodes);

            total += leftWays * rightWays;
        }

        return t[n] = total;
    }

    int numTrees(int n) {
        memset(t, -1, sizeof(t));

        return solve(n);
    }
};
