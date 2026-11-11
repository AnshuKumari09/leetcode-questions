// class Solution {
// public:
      
//     int solve(int steps,int arrlen,int idx,int currSteps){
//         if(idx<0 || idx>=arrlen){
//             return 0;
//         }
//         if(currSteps==steps){
//             if(idx==0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
            
//         }
//         int result=solve(steps,arrlen,idx+1,currSteps+1)+solve(steps,arrlen,idx-1,currSteps+1)+solve(steps,arrlen,idx,currSteps+1);
//         return result;
//     }
//     int numWays(int steps, int arrLen) {
//         return solve(steps,arrLen,0,0);
//     }
// };

// class Solution {
// public:
//       int mod=1e9 + 7;
//     int solve(int steps,int arrlen,int idx,int currSteps){
//         if(idx<0 || idx>=arrlen){
//             return 0;
//         }
//         if(currSteps==steps){
//             if(idx==0){
//                 return 1;
//             }
//             else{
//                 return 0;
//             }
            
//         }
//         int result=(solve(steps,arrlen,idx+1,currSteps+1)+solve(steps,arrlen,idx-1,currSteps+1)+solve(steps,arrlen,idx,currSteps+1))%mod;
//         return result;
//     }
//     int numWays(int steps, int arrLen) {
//         return solve(steps,arrLen,0,0);
//     }
// };

class Solution {
public:
      int mod=1e9 + 7;
     
    int solve(int steps,int arrlen,int idx,int currSteps,vector<vector<int>>&dp){
        if(idx<0 || idx>=arrlen){
            return 0;
        }
        if(currSteps==steps){
            if(idx==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[idx][currSteps]!=-1){
            return dp[idx][currSteps];
        }
        int left=solve(steps,arrlen,idx+1,currSteps+1,dp)%mod;
        int right=solve(steps,arrlen,idx-1,currSteps+1,dp)%mod;
        int stay=solve(steps,arrlen,idx,currSteps+1,dp)%mod;
       long long result = (long long)left + right + stay;
        result %= mod;
        return dp[idx][currSteps]=result;
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(steps,arrLen);
         vector<vector<int>>dp(arrLen,vector<int>(steps+1,-1));

        return solve(steps,arrLen,0,0,dp);
    }
};