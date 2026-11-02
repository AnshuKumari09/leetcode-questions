// class Solution {
// public:


//     int startAt(int idx,vector<int>& nums){
//         int n=nums.size();
//         int sum=0;
//         // for(int i=idx+1;i!=idx;i=(i+1)%n){

//         //         sum+=nums[i]*i;
//         // }
//         int i=0;
//         if(idx<n-1){
//              i=idx+1;
//         }
//         if(idx==n-1){
//             idx=0;
//         }

//         while(i!=idx){
//             sum+=nums[i]*i;
//             i=(i+1)%n;
//         }
//         return sum;
//     }
//     int maxRotateFunction(vector<int>& nums) {
//         int n=nums.size();

//         int maxElement=INT_MIN;
//         for(int i=0;i<n;i++){
//             int num=startAt(i,nums);
//             maxElement=max(maxElement,num);
//         }
//         return maxElement;

//     }
// };



// class Solution {
// public:


//     int startAt(int idx,vector<int>& nums){
//         int n=nums.size();
//         int sum=0;
//         // for(int i=idx+1;i!=idx;i=(i+1)%n){

//         //         sum+=nums[i]*i;
//         // }
//         int i=1;


//         while(i!=n){
//             idx=(idx+1)%n;
//             sum+=nums[idx]*i;
//             i++;
//         }
//         return sum;
//     }
//     int maxRotateFunction(vector<int>& nums) {
//         int n=nums.size();

//         int maxElement=INT_MIN;
//         for(int i=0;i<n;i++){
//             int num=startAt(i,nums);
//             maxElement=max(maxElement,num);
//         }
//         return maxElement;

//     }
// };


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long F = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += 1LL * i * nums[i];
        }

        long long result = F;

        for(int k = 0; k < n-1; k++) {
            long long newF = F + sum - 1LL * n * nums[n-1-k];

            result = max(result, newF);

            F = newF;
        }

        return (int)result;
    }
};
