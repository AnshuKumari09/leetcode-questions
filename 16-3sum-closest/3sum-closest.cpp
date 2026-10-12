// class Solution {
// public:
// vector<int>sums;
//     int threeSumClosest(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++){
//             for(int j=0;j<nums.size();j++){
//                 for(int k=0;k<nums.size();k++){
//                     if(i!=j && j!=k && i!=k){
//                         int sum=nums[i]+nums[j]+nums[k];
//                         sums.push_back(sum);
//                     }
//                 }
//             }
//         }
//         int result = sums[0];

//         for (int i = 0; i < sums.size(); i++) {
//             if (abs(sums[i] - target) <
//                 abs(result - target)) {

//                 result = sums[i];
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
vector<int>sums;
    int threeSumClosest(vector<int>& nums, int target) {
            int n=nums.size();
 int closest=100000;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n-2;i++){
                int l=i+1;
                int r=n-1;
               

                while(l<r){
                    int sum=nums[l]+nums[r]+nums[i];
                    if(abs(sum-target)<abs(target-closest)){
                                closest=sum;
                    }

                    if(sum>target){
                        r--;

                    }
                    else{
                        l++;
                    }
                }
            }

        return closest;
    }
};