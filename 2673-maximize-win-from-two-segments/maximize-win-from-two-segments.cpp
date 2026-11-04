class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();

        vector<int> left(n + 1, 0);
        int ans = 0, j = 0;

        for (int i = 0; i < n; i++) {
            while (prizePositions[i] - prizePositions[j] > k) {
                j++;
            }

            int cnt = i - j + 1;
            left[i + 1] = max(left[i], cnt);
        }

        j = 0;

        for (int i = 0; i < n; i++) {
            while (prizePositions[i] - prizePositions[j] > k) {
                j++;
            }

            int cnt = i - j + 1;
            ans = max(ans, cnt + left[j]);
        }

        return ans;
    }
};