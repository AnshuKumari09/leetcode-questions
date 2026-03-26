class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // consecutive horizontal segments
        vector<int> consecutiveHoriz;
        int count = 1;

        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i-1] == 1) {
                count++;
            } else {
                consecutiveHoriz.push_back(count);
                count = 1;
            }
        }
        consecutiveHoriz.push_back(count);

        // consecutive vertical segments
        vector<int> consecutiveVer;
        count = 1;

        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] - vBars[i-1] == 1) {
                count++;
            } else {
                consecutiveVer.push_back(count);
                count = 1;
            }
        }
        consecutiveVer.push_back(count);

        // max nikalna (tera compare wala logic simplify)
        int maxH = 0;
        for(int x : consecutiveHoriz) {
            maxH = max(maxH, x);
        }

        int maxV = 0;
        for(int x : consecutiveVer) {
            maxV = max(maxV, x);
        }

        int side = min(maxH, maxV) + 1;

        return side * side;
    }
};