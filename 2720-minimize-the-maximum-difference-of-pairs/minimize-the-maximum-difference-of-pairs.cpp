// class Solution {
// public:
//     int minimizeMax(vector<int>& nums, int p) {
//         int n=nums.size();
//         vector<int>vec;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                  int x=abs(nums[i]-nums[j]);
//                      vec.push_back(x);
//             }
//         }
//         sort(vec.begin(),vec.end());
//         int maxValue=-1;
//         for(int i=0;i<p;i++){
//             maxValue=max(maxValue,vec[i]);
//         }
//            return maxValue;
//     }
// };


class Solution {
public:

    bool isPossible(vector<int>& nums, int mid,int p){
        int n=nums.size();
        int count=0;
        // mujhe p pairs chahiye jinka difference diff<=mid
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(abs(nums[i]-nums[j])<=mid){
        //             count++;
        //         }
        //     }
        //     if(count==p){
        //         return true;
        //     }
        // }
         int i=0;
        while(i<n-1){
                if(abs(nums[i]-nums[i+1])<=mid){
                    count++;
                    i=i+2;
                }
                else{
                    i++;
                }         
            if(count>=p){
                return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {

        if(p==0){
            return 0;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
      int l=0;
      int r=nums[n-1]-nums[0];
       int ans=-1;
      while(l<=r){
        int mid=l+(r-l)/2;
       
        if(isPossible(nums,mid,p)){
            ans=mid;
            r=mid-1;
            
        }
        else{
           l=mid+1;
        }
      }
      return ans;
    }
};

// [1,1,2,3,7,10]
// 3,7,10]