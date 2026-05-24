// //#nums = [1,2,1,2,3], k = 2
// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int i=0;
//         int j=0;
//         int n=nums.size();
      
//         unordered_map<int,int>mp;
//         int result=0;

//         while(j<n){
//             mp[nums[j]]++;
//             while(mp.size() > k) {

//                 mp[nums[j]]--;

//                 if(mp[nums[j]] == 0) {
//                     mp.erase(nums[j]);
//                     mp[nums[i]]--;
//                      i++;
//                      j=j-1;
//                      result+=j-i+1 C k; // combination ->3c2,5C2
//                 }
                 
                
               
//             }
//         //    else if(mp.size()==k){
            
//         //        result++;
//         //      j++;
//         //    }
//         //    else{
          
//         //      j++;
//         //    }
          
//           j++;

//         }
//         return result;
//     }
// };


//#nums = [1,2,1,2,3], k = 2
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
      
        unordered_map<int,int>mp;
        int result=0;
        int extra=0;

        while(j<n){
            mp[nums[j]]++;
        if(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
           i++;
            extra=0;
        }

        while(mp[nums[i]]>1){
            mp[nums[i]]--;
            i++;
            extra++;
        }

        if(mp.size()==k){
            result+=extra+1;
        }
        j++;
        }
        return result;
    }
};