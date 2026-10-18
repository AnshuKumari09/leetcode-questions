// class Solution {
// public:


//         vector<vector<int>>direxn={{0,1},{1,0}};

//     void dfs(vector<vector<int>>& grid,int i,int j,vector<int>&vec,int currSum){
//         int m=grid.size();
//         int n=grid[0].size();
//         if(i==m-1 && j==n-1){
//                       currSum+=(grid[m-1][n-1]);
//                 vec.push_back(currSum);
      
//         }
//         if(i<0 || j<0 || i>=m || j>=n){
//             return;
//         }

//         for(auto v:direxn){
//             int n_i=i+v[0];
//             int n_j=j+v[1];
//             dfs(grid,n_i,n_j,vec,currSum+grid[i][j]);
//         }
//     }
    
//     int minPathSum(vector<vector<int>>& grid) {
//             vector<int>minSum;
//         dfs(grid,0,0,minSum,0);
//         sort(minSum.begin(),minSum.end());
//         return minSum[0];
//     }
// };

class Solution {
public:
        vector<vector<int>>direxn={{0,1},{1,0}};

    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n){
            return INT_MAX;
        }
            if(i==m-1 && j==n-1){
                return grid[i][j];
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int right=dfs(grid,i,j+1,dp);
            int left=dfs(grid,i+1,j,dp);

           return dp[i][j]=grid[i][j]+min(left,right);


    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1){
            return grid[0][0];
        }
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // dp.assign(m,vector<int>(n,-1));
            dfs(grid,0,0,dp);
            return dp[0][0];
    }
};




// class Solution {
// public:
//     vector<vector<int>> direxn = {{0,1}, {1,0}};
//     vector<vector<int>> dp;

//     int dfs(vector<vector<int>>& grid, int i, int j) {
//         int m = grid.size();
//         int n = grid[0].size();

//         // Invalid position
//         if(i >= m || j >= n) {
//             return INT_MAX;
//         }

//         // Destination reached
//         if(i == m-1 && j == n-1) {
//             return grid[i][j];
//         }

//         // Already calculated
//         if(dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int right = dfs(grid, i, j+1);
//         int down = dfs(grid, i+1, j);

//         return dp[i][j] = grid[i][j] + min(right, down);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         dp.assign(m, vector<int>(n, -1));

//         return dfs(grid, 0, 0);
//     }
// };
