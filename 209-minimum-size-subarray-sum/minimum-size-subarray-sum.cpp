class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int windowSum=nums[i];
        int currSize=0;
        int minSize=INT_MAX;
        while(j<n){
             
             if(windowSum<target){
                j++;
                if(j<n){
                   
                    windowSum+=nums[j];
                }
             }
             else{
              int currSize=j-i+1;
              minSize=min(currSize,minSize);
             
              windowSum-=nums[i];
               i++;
             }
        }
          if (minSize == INT_MAX) return 0; 
        return minSize;
    }
};