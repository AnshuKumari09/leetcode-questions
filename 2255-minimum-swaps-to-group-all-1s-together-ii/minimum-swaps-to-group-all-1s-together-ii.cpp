class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total_count1=0;
        for(int i=0;i<nums.size();i++){
            total_count1+=nums[i];
        }

        vector<int>vec;
        for(int num:nums){
            vec.push_back(num);
        }

        for(int num:nums){
            vec.push_back(num);
        }
        int target_window=total_count1;
        int maxCount=INT_MIN;
        int i=0;
        int j=0;
        int count=0;
 if(total_count1 <= 1){
    return 0;
}
        while(j<vec.size() && i<=vec.size()-total_count1){
            count+=vec[j];
            if(j-i+1==target_window){
                maxCount=max(maxCount,count);
                count-=vec[i];
                i++;
            }
                j++;
        }

        int result=total_count1-maxCount;
        return result;
    }
};