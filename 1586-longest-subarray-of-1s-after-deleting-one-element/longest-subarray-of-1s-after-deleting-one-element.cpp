// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//        int n=nums.size();
//        vector<int>vec(n);
//        int num=n;
//        for(int i=n-1;i>=0;i--){
//           vec[i]=num;
//           if(nums[i]==0){
//             num=i;
//           }
//        } 

//        int i=0;
//        int j=0;
//        int countZero=0;
//        int maxLength=0;

//        while(j<n){
//           if(nums[j]==0){
//              countZero++;
//           }
//           if(countZero==1){
//              int length=vec[j]-i;
             
//              maxLength=max(maxLength,length);
//           }
//           while(countZero>1){
//             if(nums[i]==0){
// countZero--;
//             }
            
//             i++;
//           }
            
//            maxLength=max(maxLength,j-i);
//         j++;
//        }
// return maxLength;
//     }
// };


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n=nums.size();
       vector<int>vec(n);
       int num=n;
       for(int i=n-1;i>=0;i--){
          vec[i]=num;
          if(nums[i]==0){
            num=i;
          }
       } 

       int i=0;
       int j=0;
       int countZero=0;
       int maxLength=0;

       while(j<n){
          if(nums[j]==0){
             countZero++;
          }
          
          while(countZero>1){
            if(nums[i]==0){
countZero--;
            }
            
            i++;
          }
            
           maxLength=max(maxLength,j-i);
        j++;
       }
return maxLength;
    }
};