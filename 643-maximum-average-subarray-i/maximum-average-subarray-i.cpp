// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         int n=nums.size();
//         int i=0;
//         int j=i+k-1;
//         double maxAvg=INT_MIN;
//         while(j<n){
//             double sum=0.0;
           
//             for(int z=i;z<=j;z++){
//                 sum+=nums[z];
//             }
//             double currAvg=sum/k;
//             maxAvg=max(maxAvg,currAvg);
//             i++;
//             j++;
//         }
//          return maxAvg;
//     }
// };

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=i+k-1;
        double maxAvg=INT_MIN;
        double windowSum=0.0;
        for(int i=0;i<k;i++){
            windowSum+=nums[i];
        }
        while(j<n){
            
           double currAvg=windowSum/k;
           maxAvg=max(maxAvg,currAvg);
            windowSum-=nums[i];
            i++;
            j++;
            if(j<n){
               
            windowSum+=nums[j];
            }
            
            
            
        }
         return maxAvg;
    }
};