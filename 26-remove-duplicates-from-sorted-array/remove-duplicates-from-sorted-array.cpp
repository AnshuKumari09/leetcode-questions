class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int count=1;
        while(i<n-1){
            int num=nums[i];
            bool found=false;
            for(int j=i+1;j<n;j++){
                if(nums[j]!=num){
                    found=true;
                    nums[count]=nums[j];
                    i=j;
                    count++;
                   break;

                }
               
            }
            if(found==false){
                break;
            }

             

        }
        return count;
    }
};