// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.empty()) return 0;

//         int index = 1; // Position to insert the next unique element

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] != nums[i - 1]) {
//                 nums[index] = nums[i];
//                 index++;
//             }
//         }

//         return index;
//     }
// };


// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int>visited;
//         int n=nums.size();
//         if(n==0){
//             return 0;
//         }
//          int i=0;
//          int j=0;
//         while(j<n){
//             if(visited.count(nums[j])==0){ // j visited nhi hai
//                // visited mark karo
//                visited.insert(nums[j]);
//                nums[i]=nums[j];
//                i++;
//             }
//             j++;
//         }
//        // ffill the place with spaces
      
//        return i;
//     }
// };


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        int n=nums.size();
        if(n==0){
            return 0;
        }
      int i=0;
      
      for(int j=1;j<n;j++){
          if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
             
          }
        
      }
      
       return i+1;
    }
};