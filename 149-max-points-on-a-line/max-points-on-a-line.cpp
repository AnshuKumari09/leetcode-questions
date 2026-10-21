
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int n = points.size();

//         if(n <= 2) return n;

//         vector<pair<float, float>> slopes;

//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {

//                 float slope, intercept;

//                 if(points[i][0] == points[j][0]) {
//                     // Vertical line: x = constant
//                     slope = 1e9;
//                     intercept = points[i][0];
//                 }
//                 else {
//                     slope = (float)(points[i][1] - points[j][1]) /
//                             (points[i][0] - points[j][0]);

//                     intercept = points[i][1] -
//                                 slope * points[i][0];
//                 }

//                 slopes.push_back({slope, intercept});
//             }
//         }

//         int maxCount = 0;

//         for(auto line : slopes) {
//             float slope = line.first;
//             float intercept = line.second;
//             int count = 0;

//             for(int i = 0; i < n; i++) {
//                 if(slope == 1e9) {
//                     if(points[i][0] == intercept) {
//                         count++;
//                     }
//                 }
//                 else {
//                     float satisfy = points[i][1] -
//                                     slope * points[i][0];

//                     if(abs(satisfy - intercept) < 1e-5) {
//                         count++;
//                     }
//                 }
//             }

//             maxCount = max(maxCount, count);
//         }

//         return maxCount;
//     }
// };


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> slopes;
            int duplicate = 0;
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

if (dx < 0 || (dx == 0 && dy < 0)) {
    dx = -dx;
    dy = -dy;
}

                slopes[{dx, dy}]++;
                best = max(best, slopes[{dx, dy}]);
            }

            ans = max(ans, best + duplicate + 1);
        }

        return ans;
    }
};

