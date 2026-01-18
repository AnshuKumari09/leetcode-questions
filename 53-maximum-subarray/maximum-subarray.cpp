// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxsum=INT_MIN;
//         int n=nums.size();
//         int index=0;
//         while(index<n){
//             int sum=0;

//             for(int i=index;i<n;i++){
//                  sum+=nums[i];
//                  maxsum=max(maxsum,sum);
//             }
//             index++;

//         }
//         return maxsum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
        int n=nums.size();
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;
            }
            
        }
        return maxSum;
    }
};