class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num=0;
        int n=nums.size();
        num=nums[n/2];   
        int sum=0;
        for(int i=0;i<n;i++){
            int diff=abs(nums[i]-num);
            sum+=diff;

        }
        return sum;
    }
};