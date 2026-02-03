class Solution {
public:
    
    bool traverse(vector<int>& nums){
       int p=0;
        int n=nums.size();
         int i=1;

         while(i<n){
             if(nums[i]==nums[i-1]){
                return false;
            }
            if(nums[i]<nums[i-1]){
                p=i;
                break;
            }
            i++;
        }
        if(p <=1 || p == n) return false;
      
        int q=-1;
        while(p<n){
            if(nums[p]==nums[p-1]){
                return false;
            }
            if(nums[p]>nums[p-1]){
                q=p;
                break;
            }
            p++;
        }
         if(q == -1) return false;
       
       
            while(q<n){
            if(nums[q]==nums[q-1]){
                return false;
            }
            if(nums[q]<nums[q-1]){
                return false;
            }
            q++;
        }
         
       
        if(q==n){
            return true;

        }
       return false;


        // for(int i=1;i<n;i++){
        //     if(nums[i]<nums[i-1]){
        //         p+=i;
        //         break;
        //     }
        // }
        
        // int q=0;
        // for(int i=p;i<n;i++){
        //     if(nums[i]>nums[i-1]){
        //         q+=i-1;
        //         break;
        //     }
        // }

        // for(int i=q;i<n;i++){
        //     if(nums[i]<nums[i-1]){
        //         return false;
        //     }
        // }
        
    }
    bool isTrionic(vector<int>& nums) {
       int n=nums.size();
       if(n<4){
        return false;
       } 
       if(traverse(nums)){
        return true;
       }
       return false;
    }
};