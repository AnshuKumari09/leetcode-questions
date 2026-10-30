

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
  unordered_map<int,int>mp;
  for(int i=0;i<nums.size();i++){
    mp[nums[i]]++;
  }
  
      int num=1;
        while(num>=1){
            if(mp[num]>=1){
                num++;
            }
            else{
                break;
            }
        }

        return num;
  }
};