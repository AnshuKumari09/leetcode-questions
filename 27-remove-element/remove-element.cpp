class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>pos;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                pos.push_back(i);
                count++;
            }
        }
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
        return nums.size()-count;
    }
};