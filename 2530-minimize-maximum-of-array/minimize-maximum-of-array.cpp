class Solution {
public:
     bool isPossible(vector<int>&nums,int mid){
        vector<long long> arr(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(arr[i]>mid){
              return false;
            }
            else{
                long long require = mid - arr[i];
                 arr[i+1]-=require;

            }
           
        }
     return arr[arr.size()-1]<=mid;
     }
    int minimizeArrayValue(vector<int>& nums) {
        int minL=0;
        int maxR=*max_element(nums.begin(), nums.end());
        int ans=-1;
        while(minL<=maxR){
            int mid = minL + (maxR-minL)/2;
            if(isPossible(nums,mid)){
                maxR=mid-1;
                ans=mid;
            }
            else{
                minL=mid+1;
            }
          
        }

         return ans;
    }
};